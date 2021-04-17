/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:21:11 by msamual           #+#    #+#             */
/*   Updated: 2021/04/17 17:57:19 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	navigate(t_vars *vars, char *str)
{
	if (!ft_strcmp(str, "\e[A"))
		history_prev(vars);
	else
		history_next(vars);
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
		if (!ft_strcmp(str, "\e[A") || !ft_strcmp(str, "\e[B"))
			navigate(vars, str);
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
