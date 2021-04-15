/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_support.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:01:25 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/15 14:28:14 by dmilan           ###   ########.fr       */
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

bool	is_command_executable(char *path)
{
	if (ft_string_is_relative_path(path))
	{
		if (is_directory(path))
		{
			ft_putstr_fd("Is a directory\n", 2);
			return (false);
		}
		else if (!is_file_exists(path))
		{
			ft_putstr_fd("File doesn't exist\n", 2);
			return (false);
		}
		else if (!has_execute_permission(path))
		{
			ft_putstr_fd("Don't have permission\n", 2);
			return (false);
		}
	}
	return (true);
}


bool	is_our_implementation(char *command)
{
	if (ft_strncmp(command, "cd", 2) == 0)
		return (true);
	else if (ft_strncmp(command, "echo", 4) == 0)
		return (true);
	else if (ft_strncmp(command, "env", 3) == 0)
		return (true);
	else if (ft_strncmp(command, "exit", 4) == 0)
		return (true);
	else if (ft_strncmp(command, "export", 6) == 0)
		return (true);
	else if (ft_strncmp(command, "pwd", 3) == 0)
		return (true);
	else if (ft_strncmp(command, "unset", 5) == 0)
		return (true);
	return (false);
}