/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 11:57:38 by msamual           #+#    #+#             */
/*   Updated: 2021/04/11 17:43:45 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	comment_trim(char *str)
{
	int	single_quotes;
	int	double_quotes;

	single_quotes = 0;
	double_quotes = 0;
	while (*str)
	{
		if (*str == '\"')
		{
			if (double_quotes)
				double_quotes = 0;
			else
				double_quotes = 1;
		}
		if (*str == '\'')
		{
			if (single_quotes)
				single_quotes = 0;
			else
				single_quotes = 1;
		}
		if (*str == '#' && !single_quotes && !double_quotes)
			*str = '\0';
		str++;
	}
}

void	init_com(t_command *com)
{
	com->com = ft_calloc(BUFF_SIZE, sizeof(char *));
	com->pipein = 0;
	com->pipeout = 0;
	com->redirect = 0;
}

void	print_tab(t_command *com)
{
	char **tabl = com->com;

	while (*tabl != 0)
		ft_putendl(*tabl++);
	ft_putendl(NULL);
	printf("pipein = %d pipeout = %d\n", com->pipein, com->pipeout);
}

int		pipe_hdl(t_command *com, char **cur_ptr)
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
	execute_command_struct(vars, &com);
	clear_tab(com.com);
	free(com.com);
	parsing_loop(vars, cur_ptr);
}

void	parse_row_string(t_vars *vars)
{

	char		*cur_ptr;
	char		*string;

	string = ft_strtrim(vars->history->com, " \t\r");
	cur_ptr = string;
	comment_trim(cur_ptr);
	if (check_unexpected_token(cur_ptr))
		return ;
	if (check_brackets(cur_ptr))
		return ;
	vars->brackets = 0;
	vars->end = 0;
	vars->rules = ft_strdup("$><\'\"\\~");
	parsing_loop(vars, &cur_ptr);
	//ft_putstr(string);
	free(string);
	free(vars->rules);
}
