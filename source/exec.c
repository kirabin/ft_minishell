/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:18:29 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/17 14:41:43 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: cat < unexisting_file

static void	manage_out_pipe(t_command *command, t_vars *vars)
{
	if (command->pipe_right)
	{
		close(STD_OUT);
		dup2(vars->fd[1], STD_OUT);
		// close(vars->fd[1]);
	}
	else if (command->pipe_left)
	{
		close(STD_OUT);
		dup2(vars->stdout_copy, STD_OUT);
	}
}

static void	manage_in_pipe(t_command *command, t_vars *vars)
{
	if (command->pipe_right)
	{
		close(STD_IN);
		dup2(vars->fd[0], STD_IN);
		close(vars->fd[0]);
		close(vars->fd[1]);
	}
	else if (command->pipe_left)
	{
		close(STD_IN);
		dup2(vars->stdin_copy, STD_IN);
	}
}

static void	manage_redirections(t_command *command)
{
	if (command->fd_in != -1)
	{
		close(STD_IN);
		dup2(command->fd_in, STD_IN);
	}
	if (command->fd_out != -1)
	{
		close(STD_OUT);
		dup2(command->fd_out, STD_OUT);
	}
}

void	execute_our_implementation(t_command *command, t_vars *vars)
{
	// TODO: pipes
	manage_out_pipe(command, vars);
	manage_redirections(command);
	ft_putstr_fd("Executing our implementation\n", 1);  // rm line
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

	// TODO: close fds
	pid = fork();
	if (is_child(pid))
	{
		ft_putstr_fd("Executing command\n", 1);  // rm line
		manage_out_pipe(command, vars);
		execve(command->path, command->argv, command->envp); // TODO: execute executables without #! at the start
		ft_exit(NULL);
	}
	else if (is_parent(pid))
	{
		// if (ft_strcmp(command->name, "cat") != 0)
		waitpid(-1, &g_errno, 0);
		g_errno /= 256;
		manage_in_pipe(command, vars);
	}
	else
		ft_putstr_fd("Can't execute command, fork failed\n", 2);
	return (pid);
}

void	execute_command(t_vars *vars, t_command *command)
{
	// opens pipe
	if (command->pipe_right)
	{
		if (pipe(vars->fd) == -1)
		{
			g_errno = errno;
			ft_putstr_fd("Pipe, failed, initializing undefined behavior", 2);  // TODO: exit strategy
		}
	}
	// opens redirections if there are ones
	manage_redirections(command);

	// executes my command or bin command depending on name
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
			puterror_three("Error: ", command->name,": command not found\n", 127);
	}

	// closes redirections if there was ones
	if (command->fd_in || command->fd_out)
	{
		dup2(vars->stdout_copy, STD_OUT);
		dup2(vars->stdin_copy, STD_IN);
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
