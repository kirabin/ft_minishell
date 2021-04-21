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

static void	wait_all(void)
{
	int		status;

	while (wait(&status) > 0)
	{
		if (!(g_errno == 130 || g_errno == 131))
			g_errno = status;
	}
	if (g_errno == 256)
		g_errno = 1;
}

void	execute_our_implementation(t_command *command, t_vars *vars)
{
	if (ft_strcmp(command->name, "cd") == 0)
		ft_cd(command->argv[1], &vars->env_list);
	else if (ft_strcmp(command->name, "echo") == 0)
		ft_echo(command->argv + 1);
	else if (ft_strcmp(command->name, "env") == 0)
		ft_env(vars->env_list);
	else if (ft_strcmp(command->name, "exit") == 0)
		ft_exit(command->argv + 1);
	else if (ft_strcmp(command->name, "export") == 0)
		ft_export(command->argv + 1, &vars->env_list);
	else if (ft_strcmp(command->name, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(command->name, "unset") == 0)
		ft_unset(&vars->env_list, command->argv + 1);
}

int	execute_bin_command(t_command *command, t_vars *vars)
{
	pid_t	pid;

	pid = fork();
	if (is_child(pid))
	{
		execve(command->path, command->argv, command->envp);
		ft_exit(NULL);
	}
	else if (is_parent(pid))
	{
		if (vars->semicolon)
		{
			wait_all();
		}
	}
	else
		ft_putstr_fd("Can't execute command, fork failed\n", 2);
	return (pid);
}

void	execute_command(t_vars *vars, t_command *command)
{
	open_pipes(vars, command);
	open_redirections(command);
	manage_out_pipe(command, vars);
	if (is_our_implementation(command->name))
		execute_our_implementation(command, vars);
	else
	{
		if (command->path)
		{
			if (is_command_executable(command))
				execute_bin_command(command, vars);
		}
		else
		{
			puterror_three("Error: ", command->name,
				": command not found", 127);
		}
	}
	manage_in_pipe(command, vars);
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
