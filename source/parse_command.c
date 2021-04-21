/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:50:48 by msamual           #+#    #+#             */
/*   Updated: 2021/04/20 15:39:10 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect_parse(char **cur_ptr, t_raw_command *com, char ***buf)
{
	char	buffer[9999];

	ft_bzero(buffer, 9999);
	if (**cur_ptr == '>' && *(*cur_ptr + 1) == '>')
	{
		(*cur_ptr)++;
		com->redirect = 3;
	}
	else if (**cur_ptr == '>')
		com->redirect = 2;
	else
		com->redirect = 1;
	(*cur_ptr)++;
	while (is_separator(**cur_ptr))
		(*cur_ptr)++;
	while (!ft_strchr(" |$><\'\"\\~#\0\n\t\r", **cur_ptr))
		joinchar(buffer, *(*cur_ptr)++);
	if (redirect(com, buffer))
		return (-1);
	if (ft_strchr("\0\n#><", **cur_ptr))
		(*cur_ptr)--;
	else
		new_word(buf, cur_ptr);
	return (0);
}

int	spec_symb(char **cur_ptr, char ***buf, t_vars *vars, t_raw_command *com)
{
	if (**cur_ptr == '$')
		dollar_handle(vars, **buf, cur_ptr);
	else if (**cur_ptr == '~')
		tilda_handle(vars, **buf, cur_ptr);
	else if (**cur_ptr == '\\')
		shielding(**buf, cur_ptr);
	else if (**cur_ptr == '\'')
		strong_brackets(vars);
	else if (**cur_ptr == '\"')
		soft_brackets(vars);
	else if ((**cur_ptr == '>' || **cur_ptr == '<')
		&& redirect_parse(cur_ptr, com, buf))
		return (1);
	return (0);
}

int	semicolon(char **cur_ptr, t_vars *vars)
{
	(*cur_ptr)++;
	vars->semicolon = 1;
	return (0);
}

int	parse_command(char **cur_ptr, char **buf, t_raw_command *com, t_vars *vars)
{
	*buf = ft_calloc(BUFF_SIZE, sizeof(char));
	while (is_separator(**cur_ptr))
		(*cur_ptr)++;
	while (1)
	{
		if ((ft_strchr("\0\n", **cur_ptr) || **cur_ptr == '#') && !vars->brackets)
			break ;
		if (**cur_ptr == ';' && !vars->brackets)
			return (semicolon(cur_ptr, vars));
		else if (**cur_ptr == '|' && pipe_hdl(com, cur_ptr))
			return (0);
		else if (is_separator(**cur_ptr) && !vars->brackets)
		{
			if (new_word(&buf, cur_ptr) == -1)
				return (1);
		}
		else if (!ft_strchr(vars->rules, **cur_ptr))
			joinchar(*buf, **cur_ptr);
		else
			if (spec_symb(cur_ptr, &buf, vars, com))
				return (1);
		(*cur_ptr)++;
	}
	vars->end = 1;
	return (0);
}
