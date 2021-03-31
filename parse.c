/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 11:57:38 by msamual           #+#    #+#             */
/*   Updated: 2021/03/31 18:29:54 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_com(t_command *com)
{
	com->com = ft_calloc(BUFF_SIZE, sizeof(char *));
	com->pipein = 0;
	com->pipeout = 0;
}

void	print_tab(t_command *com)
{
	char **tabl = com->com;
	
	while (*tabl != 0)
		ft_putendl(*tabl++);
	ft_putendl(NULL);
	printf("pipein = %d pipeout = %d\n", com->pipein, com->pipeout);
}

int		pipe_hdl(t_command *com)
{
	if (com->com[0] && ft_strlen(com->com[0]))
	{
		com->pipeout = 1;
		return (1);
	}
	else
	{
		com->pipein = 1;
		return (0);
	}
}

void	clear_tab(char	**buf)
{
	while (*buf)
	{
		free(*buf);
		buf++;
	}
}

void	parsing_loop(t_vars *vars, char **cur_ptr)
{
	t_command 	com;
	char		**buf;

	if (vars->end)
		return ;
	init_com(&com);
	buf = com.com;
	parse_command(cur_ptr, buf, &com, vars);
	print_tab(&com);
	clear_tab(com.com);
	free(com.com);
	parsing_loop(vars, cur_ptr);
}

void	parse_row_string(t_vars *vars)
{

	char		*cur_ptr;

	vars->end = 0;
	cur_ptr = vars->history->com;
	parsing_loop(vars, &cur_ptr);
}
