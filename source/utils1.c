/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 12:20:11 by msamual           #+#    #+#             */
/*   Updated: 2021/04/17 14:10:34 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	history_prev(t_vars *vars)
{
	if (vars->history->prev)
	{
		tputs(restore_cursor, 1, ft_putint);
		tputs(tigetstr("ed"), 1, ft_putint);
		vars->history = vars->history->prev;
		ft_putstr(vars->history->com);
		vars->cursor_pos = ft_strlen(vars->history->com);
	}
}

void	history_next(t_vars *vars)
{
	if (vars->history && vars->history->next)
	{
		vars->history = vars->history->next;
		tputs(restore_cursor, 1, ft_putint);
		tputs(tigetstr("ed"), 1, ft_putint);
		ft_putstr(vars->history->com);
		vars->cursor_pos = ft_strlen(vars->history->com);
	}
}

void	backspace(t_vars *vars, char *command)
{
	if (vars)
	{
		if (vars->cursor_pos > 0)
		{
			tputs(cursor_left, 1, ft_putint);
			tputs(delete_character, 1, ft_putint);
			while (*command)
				command++;
			*(--command) = 0;
			vars->cursor_pos--;
		}
	}
}
