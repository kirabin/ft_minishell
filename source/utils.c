/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:58:11 by msamual           #+#    #+#             */
/*   Updated: 2021/04/20 15:32:45 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_separator(char c)
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
	while (str && *str)
		joinchar(buf, *str++);
	joinchar(buf, 0);
}

void	dollar_handle(t_vars *vars, char *buf, char **input)
{
	char	buffer[9999];
	char	*var;
	char	*tmp;
	char	*str_errno;

	tmp = NULL;
	ft_bzero(buffer, 9999);
	(*input)++;
	if (**input == '?')
	{
		str_errno = ft_itoa(g_errno);
		joinstr(buf, str_errno);
		free(str_errno);
		return ;
	}
	if (!is_name_till_symbol(*input, " |$><\'\"\\~#\0\n\t\r"))
		return ;
	while (!ft_strchr(" |$><\'\"\\~#\0\n\t\r", **input))
		joinchar(buffer, *(*input)++);
	(*input)--;
	var = ft_env_list_get_value(vars->env_list, buffer);
	joinstr(buf, var);
}

void	tilda_handle(t_vars *vars, char *buf, char **cur_ptr)
{
	if (!buf[0] && *(*cur_ptr + 1) == '/')
		joinstr(buf, ft_env_list_get_value(vars->env_list, "HOME"));
	else
		joinchar(buf, **cur_ptr);
}
