/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:18:29 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/08 14:09:19 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cpp(char ***cpp)
{
	char	*temp;

	temp = **cpp;
	while (temp)
		free(temp++);
	free(*cpp);
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
	int		code;

	code = 1;
	if (ft_strncmp(command, "cd", 2) == 0)
		code = ft_cd(argv[1], *list);
	else if (ft_strncmp(command, "echo", 4) == 0)
		code = ft_echo(argv + 1);
	else if (ft_strncmp(command, "env", 3) == 0)
		ft_env(*list);
	else if (ft_strncmp(command, "exit", 4) == 0)
		ft_exit(argv[1]);  // TODO: which code to send?
	else if (ft_strncmp(command, "export", 6) == 0)
		code = ft_export(argv + 1, list);
	else if (ft_strncmp(command, "pwd", 3) == 0)
		code = ft_pwd();
	else if (ft_strncmp(command, "unset", 5) == 0)
		code = ft_unset(list, argv[0]);
	// TODO: do something with code variable?
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
		return (ft_strjoin("./", command)); // free
	}
	i = -1;
	extended_path = NULL;
	paths = ft_split(ft_env_list_get_value(list, "PATH"), ':');
	while (paths[++i])
	{
		extended_path = ft_strjoin_three(paths[i], "/", command);
		ft_putstr("\n");
		if (is_file_exists(extended_path))
			break;
		free(extended_path);
		extended_path = NULL;
	}
	// TODO: free_cpp(&paths);
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
	pid = fork();
	if (pid == -1)
		ft_putstr("Can't execute command\n");
	else if (pid == 0)
	{
		execve(command_path, argv, envp);
		return(pid);
	}
	wait(&pid);
	// TODO: free_cpp(&envp);
	return (pid);
}

void	execute_command_struct(t_vars *vars, t_command *command)
{
	char	*command_path;
	char	*command_name;
	int		pid;

	ft_putstr("execute_command_struct\n");
	command_path = get_command_path(command->com[0], vars->env_list);
	ft_putstr("execute_command_struct\n");
	command_name = get_command_name(command->com[0]);
	printf("command path: %s\n", command_path);
	printf("command name: %s\n", command_name);
	ft_putstr("execute_command_struct3\n");
	if (is_our_implementation(command_name))
	{
		ft_putstr("That's for dmilan to handle\n");
		execute_our_implementation(command_name, command->com, &vars->env_list);
	}
	else if (command_path)
	{
		free(command->com[0]);
		command->com[0] = ft_strdup(command_name);
		pid = execute_command(command_path, command->com, vars);
	}
	else
	{
		ft_putstr("Error: command not found\n");
	}
	free(command_path);
	free(command_name);
}
