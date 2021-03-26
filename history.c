/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:08:08 by msamual           #+#    #+#             */
/*   Updated: 2021/03/26 17:20:39 by msamual          ###   ########.fr       */
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
	ft_strlcpy(node->com, command, ft_strlen(command));
	vars->history = node;
}

void	print_history(t_history *cur)
{
	t_history	*node;
	node = cur;
	while (node && node->prev)
		node = node->prev;
	while (node)
	{
		ft_putendl(node->com);
		node = node->next;
	}
}