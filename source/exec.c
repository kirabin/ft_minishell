/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:18:29 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/14 17:11:49 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cpp(char **cpp)
{
	char	**temp;

	temp = cpp;
	while (temp && *temp)
		free(*temp++);
	free(cpp);
}

bool	is_our_implementation(char *command)
{
	if (ft_strncmp(command, "cd", 2) == 0)
		return true;
	else if (ft_strncmp(command, "echo", 4) == 0)
		return true;
	else if (ft_strncmp(command, "env", 3) == 0)
		return true;
	else if (ft_strncmp(command, "exit", 4) == 0)
		return true;
	else if (ft_strncmp(command, "export", 6) == 0)
		return true;
	else if (ft_strncmp(command, "pwd", 3) == 0)
		return true;
	else if (ft_strncmp(command, "unset", 5) == 0)
		return true;
	return false;
}

void	execute_our_implementation(char *command, char **argv, t_env_list **list)
{
	// TODO: manage g_errno
	if (ft_strncmp(command, "cd", 2) == 0)
		ft_cd(argv[1], *list);
	else if (ft_strncmp(command, "echo", 4) == 0)
		ft_echo(argv + 1);
	else if (ft_strncmp(command, "env", 3) == 0)
		ft_env(*list);
	else if (ft_strncmp(command, "exit", 4) == 0)
		ft_exit(argv + 1);
	else if (ft_strncmp(command, "export", 6) == 0)
		ft_export(argv + 1, list);
	else if (ft_strncmp(command, "pwd", 3) == 0)
		ft_pwd();
	else if (ft_strncmp(command, "unset", 5) == 0)
		ft_unset(list, argv + 1);
}

bool	is_file_exists(char *path)
{
	struct stat		buffer;

	if (stat(path, &buffer) == -1)
		return (false);
	return (true);
}

char	*get_command_path(char *command, t_env_list *list)
{
	char	**paths;
	char	*extended_path;
	int		i;

	if (ft_string_is_absolute_path(command))
	{
		return (ft_strdup(command));
	}
	if (ft_string_is_relative_path(command))
	{
		return (ft_strjoin("./", command));
	}
	i = -1;
	extended_path = NULL;
	paths = ft_split(ft_env_list_get_value(list, "PATH"), ':');
	while (paths && paths[++i])
	{
		extended_path = ft_strjoin_three(paths[i], "/", command);
		ft_putstr("\n");
		if (is_file_exists(extended_path))
			break;
		free(extended_path);
		extended_path = NULL;
	}
	free_cpp(paths);
	return (extended_path);
}

char	*get_command_name(char *command)
{
	int		len;

	len = ft_strlen(command) - 1;
	if (ft_string_is_path(command))
	{
		while (command[len] != '/')
			len--;
		return (ft_strdup(command + len + 1));
	}
	else
	{
		return (ft_strdup(command));
	}
}

int		execute_command(char *command_path, char **argv, t_vars *vars)
{
	int		pid;
	char	**envp;

	envp = ft_env_to_charpp(vars->env_list);
	if (!envp)
		;
	if (vars->pipeout == 1)
	{
		pipe(vars->fd);  // protect from -1
	}
	pid = fork();
	if (pid == -1)
		ft_putstr("Can't execute command\n");
	else if (pid == 0)
	{
		// signal(SIGINT, handle_sign);
		if (vars->pipeout == 1)
		{
			dup2(vars->fd[1], STD_OUT);
		}
		else
		{
			// dup2(0, STD_IN);
			dup2(vars->stdout_copy, STD_OUT);
		}

		execve(command_path, argv, envp);
		// return(pid);
	}
	else
	{
		wait(&pid);
		if (vars->pipeout == 1)
		{
			dup2(vars->fd[0], STD_IN);
			close(vars->fd[0]);
			close(vars->fd[1]);
		}
		if (vars->pipein == 1)
		{
			dup2(vars->stdin_copy, STD_IN);
		}

	}
	free_cpp(envp);
	return (pid);
}

void	execute_command_struct(t_vars *vars, t_command *command)
{
	char	*command_path;
	char	*command_name;
	// int		pid;

	command_path = get_command_path(command->com[0], vars->env_list);
	command_name = get_command_name(command->com[0]);
	printf("command path: %s\n", command_path);
	printf("command name: %s\n", command_name);
	vars->pipein = command->pipein;
	vars->pipeout = command->pipeout;
	printf("pipes: %d, %d\n", vars->pipein, vars->pipeout);
	if (is_our_implementation(command_name))
	{
		execute_our_implementation(command_name, command->com, &vars->env_list);
	}
	else if (command_path)
	{
		free(command->com[0]);
		command->com[0] = ft_strdup(command_name);
		execute_command(command_path, command->com, vars);
	}
	else
	{
		ft_putstr("Error: command not found\n");
		g_errno = 127;
	}
	free(command_path);
	free(command_name);
}
