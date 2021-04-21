/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 11:57:38 by msamual           #+#    #+#             */
/*   Updated: 2021/04/20 13:26:42 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_com(t_raw_command *com)
{
	com->com = ft_calloc(BUFF_SIZE, sizeof(char *));
	com->pipein = 0;
	com->pipeout = 0;
	com->redirect = 0;
	com->redirect_in = -1;
	com->redirect_out = -1;
}

int	pipe_hdl(t_raw_command *com, char **cur_ptr)
{
	if (com->com[0] && ft_strlen(com->com[0]))
	{
		com->pipeout = 1;
		return (1);
	}
	else
	{
		(*cur_ptr)++;
		while (is_separator(**cur_ptr))
			(*cur_ptr)++;
		com->pipein = 1;
		return (0);
	}
}

void	clear_tab(t_raw_command *com)
{
	char	**str;

	str = com->com;
	if (com->redirect_in != -1)
		close(com->redirect_in);
	if (com->redirect_out != -1)
		close(com->redirect_out);
	while (*str)
	{
		free(*str);
		str++;
	}
	free(com->com);
}

void	parsing_loop(t_vars *vars, char **cur_ptr)
{
	t_raw_command	com;
	char			**buf;

	if (vars->end)
		return ;
	init_com(&com);
	buf = com.com;
	vars->semicolon = 0;
	if (parse_command(cur_ptr, buf, &com, vars))
	{
		clear_tab(&com);
		return ;
	}
	if (ft_strchr("\0\n", **cur_ptr) || **cur_ptr == '#')
	{
		vars->end = 1;
		vars->semicolon = 1;
	}
	execute_raw_command(vars, &com);
	clear_tab(&com);
	parsing_loop(vars, cur_ptr);
}

void	parse_row_string(t_vars *vars)
{
	char	*cur_ptr;
	char	*string;
	char	*save;

	vars->term.c_lflag |= (ECHO);
	vars->term.c_lflag |= (ICANON);
	vars->term.c_lflag |= (ISIG);
	tcsetattr(0, TCSANOW, &vars->term);
	string = ft_strdup(vars->history->com);
	comment_trim(string);
	save = ft_strtrim(string, " \t\r");
	cur_ptr = save;
	if (check_unexpected_token(cur_ptr)
		|| check_brackets(cur_ptr))
		;
	else
	{
		vars->brackets = 0;
		vars->end = 0;
		vars->rules = ft_strdup("$><\'\"\\~");
		parsing_loop(vars, &cur_ptr);
	}
	free(string);
	free(save);
	free(vars->rules);
}
