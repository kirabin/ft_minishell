/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 11:57:38 by msamual           #+#    #+#             */
/*   Updated: 2021/03/31 09:23:56 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_com(t_command *com)
{
	com->com = ft_calloc(BUFF_SIZE, sizeof(char *));
	com->pipe = 0;
}

void	print_tab(char **tabl)
{
	while (*tabl != 0)
		ft_putendl(*tabl++);
	ft_putendl(NULL);
}

void	pipe_hdl(void)
{
	ft_putendl("PIPE");
}

void	clear_tab(char	**buf)
{
	while (*buf)
	{
		free(*buf);
		buf++;
	}
}

void	parsing_loop(t_vars *vars, char **cur_ptr, int pipe)
{
	t_command 	com;
	char		**buf;

	if (vars->end)
		return ;
	if (pipe)
		pipe_hdl();
	init_com(&com);
	buf = com.com;
	parse_command(cur_ptr, buf, &com, vars);
	print_tab(buf);
	clear_tab(com.com);
	free(com.com);
	parsing_loop(vars, cur_ptr, com.pipe);
}

void	parse_row_string(t_vars *vars)
{

	char		*cur_ptr;

	vars->end = 0;
	cur_ptr = vars->history->com;
	parsing_loop(vars, &cur_ptr, 0);
}
