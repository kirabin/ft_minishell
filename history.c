/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:08:08 by msamual           #+#    #+#             */
/*   Updated: 2021/03/27 15:06:49 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_history(t_vars *vars)
{
	vars->history = NULL;
}

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

void	print_history(t_history *cur)
{
	t_history	*node;
	node = cur;
	while (node && node->prev)
		node = node->prev;
	write(1, "\n", 1);
	while (node)
	{
		ft_putendl(node->com);
		node = node->next;
	}
	write(1, "\n", 1);
}