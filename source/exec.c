/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:18:29 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/15 17:20:28 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_our_implementation(t_command *command, t_env_list **list)
{
	// TODO: manage g_errno
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



int		execute_command(t_command *command, t_vars *vars)
{
	pid_t	pid;
	// int		ret;
	char	**envp;

	// TODO: manage g_errno
	envp = ft_env_to_charpp(vars->env_list);
	if (!envp)
		;
	if (command->pipe_right)
	{
		pipe(vars->fd);  // protect from -1
	}
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
		{
			// dup2(0, STD_IN);
			dup2(vars->stdout_copy, STD_OUT);
		}

		// int pid2 = fork();
		// if (pid2 == 0)
		execve(command->path, command->argv, envp);
		// wait(&pid2);
		exit(0);
	}
	else
	{
		wait(&pid);
		if (command->pipe_right)
		{
			dup2(vars->fd[0], STD_IN);
			close(vars->fd[0]);
			close(vars->fd[1]);
		}
		else if (command->pipe_left)
		{
			dup2(vars->stdin_copy, STD_IN);
		}
	}
	free_cpp(envp);
	return (pid);
}



void	execute_raw_command(t_vars *vars, t_raw_command *raw_command)
{
	t_command	*command;

	command = get_command_from_raw(vars, raw_command);
	if (!command || !is_command_executable(command->path))
		;
	else if (is_our_implementation(command->name))
		execute_our_implementation(command, &vars->env_list);
	else
	{
		if (command->path)
			execute_command(command, vars);
		else
			puterror("Error: command not found\n", 127);
	}
	free_t_command(command);
}
