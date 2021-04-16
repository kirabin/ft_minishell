/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:27:09 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/16 11:37:51 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_command_path(char *command, t_env_list *list)
{
	char	**paths;
	char	*extended_path;
	int		i;

	if (ft_string_is_absolute_path(command))
		return (ft_strdup(command));
	if (ft_string_is_relative_path(command))
		return (ft_strjoin("./", command));
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

char	*get_command_name(char *path)
{
	int		len;

	len = ft_strlen(path) - 1;
	if (ft_string_is_path(path))
	{
		while (path[len] != '/')
			len--;
		return (ft_strdup(path + len + 1));
	}
	else
		return (ft_strdup(path));
}

void	free_t_command(t_command *command)
{
	if (command)
	{
		free(command->path);
		free(command->name);
		free_cpp(command->envp);
	}
	free(command);
}

t_command	*get_command_from_raw(t_vars *vars, t_raw_command *raw_command)
{
	t_command	*command;

	command = malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->path = get_command_path(raw_command->com[0], vars->env_list);
	command->name = get_command_name(raw_command->com[0]);
	free(raw_command->com[0]);
	raw_command->com[0] = ft_strdup(command->name);
	command->argv = raw_command->com;
	command->pipe_left = raw_command->pipein;
	command->pipe_right = raw_command->pipeout;
	command->envp = ft_env_to_charpp(vars->env_list);
	if (!command->envp)
	{
		free(command->path);
		free(command->name);
		free(command);
		return (NULL);
	}
	return (command);
}