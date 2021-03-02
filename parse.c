/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 11:57:38 by msamual           #+#    #+#             */
/*   Updated: 2021/03/02 12:34:20 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	skip_spaces(char **input, char *buf)
{
	joinchar(buf, ' ');
	while (ft_strchr(" \t\r", **input))
		*input += 1;
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

void	parse_row_string(t_vars *vars)
{
	char	buf[9999];
	char	*input;
	char	*tmp;

	ft_bzero(buf, 9999);
	tmp = ft_strdup(vars->raw_input);
	input = ft_strtrim(tmp, " \t\r");
	while(*input)
	{
		if (ft_isalnum(*input) || *input == '/' || *input == '-')
			joinchar(buf, *input++);
		else if (ft_strchr(" \t\r", *input))
			skip_spaces(&input, buf);
		else if (*input++ == '$')
			dollar_handle(vars, buf, &input);
		else
			break ;
	}
	joinchar(buf, '\0');
	ft_putendl(buf);
}