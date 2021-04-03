/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:18:29 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/03 13:29:00 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cpp(char **cpp)
{
	char	*temp;

	temp = *cpp;
	while (temp)
		free(temp++);
	free(cpp);
}

bool	is_our_implementation(char *command)
{
	if (command == "cd")
		return true;
	else if (command == "echo")
		return true;
	else if (command == "env")
		return true;
	else if (command == "exit")
		return true;
	else if (command == "export")
		return true;
	else if (command == "pwd")
		return true;
	else if (command == "unset")
		return true;
	return false;
}

void	execute_our_implementation(char *command, char **argv, t_env_list *list)
{
	// Check whether there is more args or not?
	if (command == "cd")
		ft_cd(argv[0]);
	else if (command == "echo")
		;
	else if (command == "env")
		ft_env(list);
	else if (command == "exit")
		ft_exit();
	else if (command == "export")
		;
	else if (command == "pwd")
		ft_pwd();
	else if (command == "unset")
		ft_unset(&list, argv[0]);
}

bool	is_file_exists(char *path)
{
	struct stat		buffer;

	if (stat(path, &buffer) == -1)
		return (false);
	return (true);
}



char	*get_command_path(t_command *command, t_env_list *list)
{
	char	**paths;
	char	*extended_path;
	int		i;

	if (string_is_absolute_path(command->com[0]))
		return (command->com[0]);
	i = -1;
	extended_path = NULL;
	paths = ft_split(ft_env_list_get_value(list, "PATH"), ':');
	while (paths[++i])
	{
		extended_path = ft_strjoin(paths[i], command->com[0]);
		if (is_file_exists(extended_path))
			break;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (extended_path);
}

char	*get_command_name(t_command *command)
{
	if ()
}

void	execute_command(char *command_path, char **argv, t_env_list *list)
{
	int		pid;

	pid = fork();
	if (pid == -1)
		ft_putstr("Can't execute command\n");
	else if (pid == 0)
		execve(command_path, argv, ft_env_to_charpp(list));
	else
		ft_putstr("parend does nothing\n");
}


void	execute_command_struct(t_vars *vars, t_command *command)
{
	char	*command_path;
	char	*command_name;


	command_path = get_command_path(command, vars->env_list);
	command_name = get_command_name(command);
	if (is_our_implementation(command))
		execute_our_implementation(command, splitted + 1, list);
	else if (command_path)
	{
		execute_command(command_path, splitted + 1, )
		//wait;
	}
	else
	{
		ft_putstr("Error: command not found\n");
	}
	free(command_path);
	free_cpp(splitted);
}


// void	execute_command_struct(char *str, t_env_list *list)
// {
// 	char	**splitted;
// 	char	*command;
// 	char	*command_path;

// 	splitted = ft_split(str, ' ');
// 	command = splitted[0];
// 	command_path = get_command_path(command, list);
// 	if (is_our_implementation(command))
// 		execute_our_implementation(command, splitted + 1, list);
// 	else if (command_path)
// 	{
// 		execute_command(command_path, splitted + 1, )
// 		//wait;
// 	}
// 	else
// 	{
// 		ft_putstr("Error: command not found\n");
// 	}
// 	free(command_path);
// 	free_cpp(splitted);
// }