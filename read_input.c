/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:21:11 by msamual           #+#    #+#             */
/*   Updated: 2021/03/26 18:29:39 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	history_prev(t_vars *vars, char *command, char *thread)
{
	if (vars->history)
	{
		ft_strlcpy(thread, command, ft_strlen(command));
		tputs(restore_cursor, 1, ft_putint);
		tputs(tigetstr("ed"), 1, ft_putint);
		ft_bzero(command, 1000);
		ft_memmove(command, vars->history->com, ft_strlen(vars->history->com));
		vars->history = vars->history->prev;
		ft_putstr(command);
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

void	add_to_command(char *str, char *command, int ret, t_vars *vars)
{
	int		i;

	(void)vars;
	i = -1;
	while (*command)
		command++;
	while (++i < ret)
		command[i] = str[i];
	write(1, str, ret);
}

void	execute_command(t_vars * vars, char *command)
{
	write(1, "\n", 1);
	if (ft_strlen(command) > 0)
	{
		push_to_command_history(vars, command);
		ft_putstr(command);
		write(1, "\n", 1);
	}
}

void	read_input(t_vars *vars)
{
	char	str[100];
	char	command[1000];
	char	thread[1000];
	int		ret;

	ft_bzero(command, 1000);
	ft_bzero(thread, 1000);
	tgetent(0, vars->term_name);
	tputs(save_cursor, 1, ft_putint);
	while (1)
	{
		ret = read(0, str, 500);
		str[ret] = 0;
		if (!ft_strcmp(str, "\e[A"))
			history_prev(vars, command, thread);
		else if (!ft_strcmp(str, "\e[B"))
			history_next(vars);
		else if (!ft_strcmp(str, "\e[D"))
			move_left(vars);
		else if (!ft_strcmp(str, "\e[C"))
			move_right(vars);
		else if (!ft_strcmp(str, "\177"))
			backspace(vars, command);
		else if (ft_strcmp(str, "\n"))
			add_to_command(str, command, ret, vars);
		else
			break ;
	}
	execute_command(vars, command);
}
