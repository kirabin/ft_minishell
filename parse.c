/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 11:57:38 by msamual           #+#    #+#             */
/*   Updated: 2021/03/08 17:42:30 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_com(t_command *com)
{
	com->com = ft_calloc(BUFF_SIZE, sizeof(char *));
	com->pipe = 0;
}

/*void	skip_spaces(char **input, char *buf)
{
	joinchar(buf, ' ');
	while (ft_strchr(" \t\r", **input))
		*input += 1;
}*/

void	print_tab(char **tab)
{
	while (*tab != 0)
		ft_putendl(*tab++);
	ft_putendl(NULL);
}

void	pipe_hdl(void)
{
	ft_putendl("PIPE");
}

void	clear_tab(char	**buf)
{
	while (*buf++)
		free(*buf);
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
	parsing_loop(vars, cur_ptr, com.pipe);
}

void	parse_row_string(t_vars *vars)
{

	char		*cur_ptr;

	vars->end = 0;
	cur_ptr = vars->raw_input;
	parsing_loop(vars, &cur_ptr, 0);
}