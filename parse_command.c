/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:50:48 by msamual           #+#    #+#             */
/*   Updated: 2021/03/08 18:52:25 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_separator(char c)
{
	if (ft_strchr(" \t\r", c))
		return (1);
	return (0);
}

void	joinchar(char *buf, char c)
{
	while (*buf)
		buf++;
	*buf = c;
}

void	joinstr(char *buf, char *str)
{
	while(*str)
		joinchar(buf, *str++);
}

void	dollar_handle(t_vars *vars, char *buf, char **input)
{
	char	buffer[9999];
	char	*var;

	ft_bzero(buffer, 9999);
	while(ft_isalnum(**input))
		joinchar(buffer, *(*input)++);
	joinchar(buffer, '\0');
	if ((var = ft_env_list_get_value(vars->env_list, buffer)))
		joinstr(buf, var);
}

void		spec_symb(char **cur_ptr, char ***buf, t_command *com, t_vars *vars)
{
	
	if (is_separator(**cur_ptr))
	{
		while (is_separator(**cur_ptr && *((*cur_ptr)+1)))
			(*cur_ptr)++;
		*buf += 1;
		**buf = ft_calloc(BUFF_SIZE, sizeof(char));
	}
	else if (**cur_ptr == '$')
		dollar_handle(vars, **buf, cur_ptr);
	else if (**cur_ptr == '|')
		com->pipe = 1;
}

void		parse_command(char **cur_ptr, char **buf, t_command *com, t_vars *vars)
{

	*buf = ft_calloc(BUFF_SIZE, sizeof(char));
	while (is_separator(**cur_ptr))
		(*cur_ptr)++;
	while (**cur_ptr != 0 && **cur_ptr != '\n')
	{
		if (com->pipe)
			return ;
		if (ft_isalnum(**cur_ptr))
			joinchar(*buf, **cur_ptr);
		else
			spec_symb(cur_ptr, &buf, com, vars);
		(*cur_ptr)++;
	}
	vars->end = 1;
}