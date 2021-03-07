/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:50:48 by msamual           #+#    #+#             */
/*   Updated: 2021/03/07 17:55:45 by msamual          ###   ########.fr       */
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

void	spec_symb(char **cur_ptr, char ***buf, int *pipein, int *pipeout)
{
	(void)cur_ptr;
	(void)pipein;
	(void)pipeout;
	if (is_separator(**cur_ptr))
	{
		*buf++;
		*cur++;
	}
	ft_putendl("Special symbol");
	return ;
}

int		parse_command(char **cur_ptr, char **buf, int *pipein, int *pipeout)
{
	*buf = ft_calloc(BUFF_SIZE, sizeof(char));
	while (**cur_ptr != 0 && **cur_ptr != '\n')
	{
		if (ft_isalnum(**cur_ptr))
		{
			joinchar(*buf, **cur_ptr);
			++*cur_ptr;
		}
		else
			spec_symb(cur_ptr, &buf, pipein, pipeout);
	}
	if (**cur_ptr == '\0' || **cur_ptr == '\n')
		return (0);
	return (1);
}