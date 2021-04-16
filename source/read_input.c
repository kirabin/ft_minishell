/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:21:11 by msamual           #+#    #+#             */
/*   Updated: 2021/04/16 18:23:13 by dmilan           ###   ########.fr       */
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

void	move_left(t_vars *vars)
{
	if (vars)
		return ;
}

void	move_right(t_vars *vars)
{
	if (vars)
		return ;
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

void	add_to_command(t_vars *vars, char *str, int ret, char *command)
{
	int	i;

	i = -1;
	while (*command)
		command++;
	while (++i < ret)
		command[i] = str[i];
	write(1, str, ret);
	vars->cursor_pos += ret;
}

void	parsing(t_vars *vars)
{
	vars->cursor_pos = 0;
	write(1, "\n", 1);
	if (ft_strlen(vars->history->com) > 0)
	{
		parse_row_string(vars);
		if (vars->history && vars->history->next)
		{
			remove_current_input(vars->history);
			push_to_command_history(vars, vars->history->com);
		}
	}
	else if (vars->history->next)
	{
		remove_elem_hist(&(vars->history));
		remove_elem_hist(&(vars->history));
	}
	else
		remove_elem_hist(&(vars->history));
}

void	read_input(t_vars *vars)
{
	char	str[100];
	int		ret;

	push_to_command_history(vars, "");
	while (1)
	{
		ret = read(0, str, 100);
		str[ret] = 0;
		if (!ft_strcmp(str, "\e[A"))
			history_prev(vars);
		else if (!ft_strcmp(str, "\e[B"))
			history_next(vars);
		else if (!ft_strcmp(str, "\e[D") || !ft_strcmp(str, "\e[C")
			|| !ft_strcmp(str, "\t"))
			;
		else if (!ft_strcmp("\4", str))
			ctrl_d(vars);
		else if (!ft_strcmp(str, "\177") || *str == '\b')
			backspace(vars, vars->history->com);
		else if (str[0] == 27 && !ft_isalnum(str[0]))
			continue ;
		else if (ft_strcmp(str, "\n"))
			add_to_command(vars, str, ret, vars->history->com);
		else
			break ;
	}
	parsing(vars);
}
