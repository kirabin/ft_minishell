/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_support.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:01:25 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/17 14:45:10 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_file_exists(char *path)
{
	struct stat		stats;

	if (stat(path, &stats) == -1)
		return (false);
	return (true);
}

bool	is_directory(char *path)
{
	struct stat		stats;

	if (stat(path, &stats) == 0 && S_ISDIR(stats.st_mode))
		return (true);
	return (false);
}

bool	has_execute_permission(char *path)
{
	struct stat		stats;

	if (stat(path, &stats) == 0 && stats.st_mode & S_IXUSR)
		return (true);
	return (false);
}

bool	is_command_executable(t_command *command)
{
	if (is_directory(command->path))
	{
		puterror_three(NULL, command->raw_path, ": is a directory", 126);
		return (false);
	}
	else if (!is_file_exists(command->path))
	{
		puterror_three(NULL, command->raw_path,
			": No such file or directory", 127);
		return (false);
	}
	else if (!has_execute_permission(command->path))
	{
		puterror_three(NULL, command->raw_path, ": Permission denied", 126);
		return (false);
	}
	return (true);
}

bool	is_our_implementation(char *command)
{
	if (ft_strcmp(command, "cd") == 0)
		return (true);
	else if (ft_strcmp(command, "echo") == 0)
		return (true);
	else if (ft_strcmp(command, "env") == 0)
		return (true);
	else if (ft_strcmp(command, "exit") == 0)
		return (true);
	else if (ft_strcmp(command, "export") == 0)
		return (true);
	else if (ft_strcmp(command, "pwd") == 0)
		return (true);
	else if (ft_strcmp(command, "unset") == 0)
		return (true);
	return (false);
}
