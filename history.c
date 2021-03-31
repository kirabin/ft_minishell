/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:08:08 by msamual           #+#    #+#             */
/*   Updated: 2021/03/31 12:47:15 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	push_to_command_history(t_vars *vars, char *command)
{
	t_history	*node;
	t_history	*current;

	while(vars->history && vars->history->next)
		vars->history = vars->history->next;
	node = ft_calloc(1, sizeof(t_history));
	current = vars->history;
	if (current)
		current->next = node;
	node->prev = current;
	node->next = NULL;
	ft_strlcpy(node->com, command, ft_strlen(command) + 1);
	vars->history = node;
}

void	remove_current_input(t_history *history)
{
	t_history *tmp;

	tmp = history;
	while (tmp->next->next)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
	
}

t_history	*to_end_of_list(t_history *hist)
{
	if (!hist)
		return (NULL);
	while (hist->next)
		hist = hist->next;
	return (hist);
}

void	remove_elem_hist(t_history **history)
{
	t_history	*prev;
	t_history	*next;
	t_history	*tmp;

	tmp = *history;
	prev = (*history)->prev;
	next = (*history)->next;
	if (!prev && !next)
		*history = NULL;
	if (prev)
	{
		prev->next = next;
		*history = prev;
	}
	if (next)
	{
		next->prev = prev;
		*history = next;
		
	}
	free(tmp);
	*history = to_end_of_list(*history);
}

void	init_history(t_vars *vars)
{
	int fd;
	char *line;

	fd = open(".history.txt", O_RDONLY);
	if (fd < 0)
		vars->history = NULL;
	else
	{
		while (get_next_line(fd, &line) > 0)
		{
			push_to_command_history(vars, line);
			free(line);
		}
		push_to_command_history(vars, line);
		free(line);
		close(fd);
	}
}