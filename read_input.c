/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:21:11 by msamual           #+#    #+#             */
/*   Updated: 2021/03/27 15:05:04 by msamual          ###   ########.fr       */
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
		tputs(cursor_left, 1, ft_putint);
		tputs(delete_character, 1, ft_putint);
		while (*command)
			command++;
		*(--command) = 0;
	}
}

void	add_to_command(char *str, int ret, char *command)
{
	int		i;

	i = -1;
	while (*command)
		command++;
	while (++i < ret)
		command[i] = str[i];
	write(1, str, ret);
}

void	execute_command(t_vars * vars)
{
	write(1, "\n", 1);
	if (ft_strlen(vars->history->com) > 0)
	{
		ft_putstr(vars->history->com);
		write(1, "\n", 1);
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
	print_history(vars->history);
}

void	read_input(t_vars *vars)
{
	char	str[100];
	int		ret;

	tgetent(0, vars->term_name);
	tputs(save_cursor, 1, ft_putint);
	push_to_command_history(vars, "");
	while (1)
	{
		ret = read(0, str, 500);
		str[ret] = 0;
		if (!ft_strcmp(str, "\e[A"))
			history_prev(vars);
		else if (!ft_strcmp(str, "\e[B"))
			history_next(vars);
		else if (!ft_strcmp(str, "\e[D"))
			move_left(vars);
		else if (!ft_strcmp(str, "\e[C"))
			move_right(vars);
		else if (!ft_strcmp(str, "\177"))
			backspace(vars, vars->history->com);
		else if (ft_strcmp(str, "\n"))
			add_to_command(str, ret, vars->history->com);
		else
			break ;
	}
	execute_command(vars);
}
