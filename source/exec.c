/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:18:29 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/16 11:42:09 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_our_implementation(t_command *command, t_env_list **list)
{
	// TODO: pipes
	if (ft_strncmp(command->name, "cd", 2) == 0)
		ft_cd(command->argv[1], *list);
	else if (ft_strncmp(command->name, "echo", 4) == 0)
		ft_echo(command->argv + 1);
	else if (ft_strncmp(command->name, "env", 3) == 0)
		ft_env(*list);
	else if (ft_strncmp(command->name, "exit", 4) == 0)
		ft_exit(command->argv + 1);
	else if (ft_strncmp(command->name, "export", 6) == 0)
		ft_export(command->argv + 1, list);
	else if (ft_strncmp(command->name, "pwd", 3) == 0)
		ft_pwd();
	else if (ft_strncmp(command->name, "unset", 5) == 0)
		ft_unset(list, command->argv + 1);
}


int		execute_bin_command(t_command *command, t_vars *vars)
{
	pid_t	pid;
	// int		ret;

	// TODO: manage g_errno
	if (command->pipe_right)
		pipe(vars->fd);  // protect from -1
	pid = fork();
	if (pid == -1)
		ft_putstr("Can't execute command\n");
	else if (pid == 0)
	{
		if (command->pipe_right)
		{
			dup2(vars->fd[1], STD_OUT);
		}
		else if (command->pipe_left)
			dup2(vars->stdout_copy, STD_OUT);

		execve(command->path, command->argv, command->envp);
		g_errno = 1;
		exit(0);
	}
	else
	{
		wait(&pid);
		if (command->pipe_right)
		{
			dup2(vars->fd[0], STD_IN);
			// close(vars->fd[0]);
			// close(vars->fd[1]);
		}
		else if (command->pipe_left)
			dup2(vars->stdin_copy, STD_IN);
	}
	return (pid);
}



void	execute_command(t_vars *vars, t_command *command)
{
	if (is_our_implementation(command->name))
		execute_our_implementation(command, &vars->env_list);
	else
	{
		if (command->path && is_command_executable(command->path))
			execute_bin_command(command, vars);
		else
			puterror("Error: command not found\n", 127);
	}
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
