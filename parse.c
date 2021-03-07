/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 11:57:38 by msamual           #+#    #+#             */
/*   Updated: 2021/03/07 16:27:49 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_com(t_command *com)
{
	com->com = ft_calloc(BUFF_SIZE, sizeof(char *));
	com->pipein = 0;
	com->pipeout = 0;
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

void	parse_row_string(t_vars *vars)
{
	t_command	com;
	char		**buf;
	char		*cur_ptr;

	init_com(&com);
	buf = com.com;
	cur_ptr = vars->raw_input;
	while (parse_command(&cur_ptr, buf, &com.pipein, &com.pipeout))
		print_tab(buf);
	print_tab(buf);
}