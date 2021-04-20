/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:18:29 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/19 11:40:43 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_our_implementation(t_command *command, t_vars *vars)
{
	manage_out_pipe(command, vars);
	open_redirections(command);
	if (ft_strncmp(command->name, "cd", 2) == 0)
		ft_cd(command->argv[1], vars->env_list);
	else if (ft_strncmp(command->name, "echo", 4) == 0)
		ft_echo(command->argv + 1);
	else if (ft_strncmp(command->name, "env", 3) == 0)
		ft_env(vars->env_list);
	else if (ft_strncmp(command->name, "exit", 4) == 0)
		ft_exit(command->argv + 1);
	else if (ft_strncmp(command->name, "export", 6) == 0)
		ft_export(command->argv + 1, &vars->env_list);
	else if (ft_strncmp(command->name, "pwd", 3) == 0)
		ft_pwd();
	else if (ft_strncmp(command->name, "unset", 5) == 0)
		ft_unset(&vars->env_list, command->argv + 1);
	manage_in_pipe(command, vars);
}

int	execute_bin_command(t_command *command, t_vars *vars)
{
	pid_t	pid;

	pid = fork();
	if (is_child(pid))
	{
		manage_out_pipe(command, vars);
		if (vars->fd[1] > 1)
			close(vars->fd[1]);
		execve(command->path, command->argv, command->envp);
		ft_exit(NULL);
	}
	else if (is_parent(pid))
	{
		wait(&g_errno);
		if (g_errno == 256)
			g_errno = 1;
		manage_in_pipe(command, vars);
	}
	else
		ft_putstr_fd("Can't execute command, fork failed\n", 2);
	return (pid);
}

void	execute_command(t_vars *vars, t_command *command)
{
	open_pipes(vars, command);
	open_redirections(command);
	if (is_our_implementation(command->name))
		execute_our_implementation(command, vars);
	else
	{
		if (command->path)
		{
			if (is_command_executable(command->raw_path))
				execute_bin_command(command, vars);
		}
		else
		{
			puterror_three("Error: ", command->name,
				": command not found", 127);
		}
	}
	close_redirections(vars, command);
}

void	execute_raw_command(t_vars *vars, t_raw_command *raw_command)
{
	t_command	*command;

	command = get_command_from_raw(vars, raw_command);
	if (!command)
		return ;
	execute_command(vars, command);
	free_t_command(command);
}
