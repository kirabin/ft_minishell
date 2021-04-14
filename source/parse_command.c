/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:50:48 by msamual           #+#    #+#             */
/*   Updated: 2021/04/14 16:00:45 by msamual          ###   ########.fr       */
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
	while(str && *str)
		joinchar(buf, *str++);
	joinchar(buf, 0);
}

void	dollar_handle(t_vars *vars, char *buf, char **input)
{
	char	buffer[9999];
	char	*var;
	char	*tmp;

	tmp = NULL;
	ft_bzero(buffer, 9999);
	(*input)++;
	if (**input == '?')
	{
		joinstr(buf, ft_itoa(g_errno));
		free(tmp);
		return ;
	}
	while(!ft_strchr(" |$><\'\"\\~#\0\n\t\r", **input))
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

void	shielding(char *buf, char **cur_ptr)
{
	(*cur_ptr)++;
	joinchar(buf, **cur_ptr);
}

void	strong_brackets(t_vars *vars)
{
	if (!vars->brackets)
	{
		vars->brackets = 2;
		free(vars->rules);
		vars->rules = ft_strdup("\'");
	}
	else
	{
		vars->brackets = 0;
		free(vars->rules);
		vars->rules = ft_strdup("$><\'\"\\~");
	}
}

void	soft_brackets(t_vars *vars)
{
	if (!vars->brackets)
	{
		vars->brackets = 1;
		free(vars->rules);
		vars->rules = ft_strdup("$\\\"");
	}
	else
	{
		vars->brackets = 0;
		free(vars->rules);
		vars->rules = ft_strdup("$><\'\"\\~");
	}
}

int		new_word(char ***buf, char **cur_ptr)
{

	while (is_separator(*(*cur_ptr + 1)))
			(*cur_ptr)++;
	if (!ft_strchr("#|;><\0\n", *(*cur_ptr + 1)))
	{
		(*buf)++;
		**buf = ft_calloc(BUFF_SIZE, sizeof(char));
	}
	return (0);
}

void	redirect_parse(char **cur_ptr, t_command *com, char ***buf)
{
	char	buffer[9999];
	int		check;

	ft_bzero(buffer, 9999);
	if (**cur_ptr == '>' && *(*cur_ptr + 1) == '>')
		com->redirect = 3;
	else if (**cur_ptr == '>')
		com->redirect = 2;
	else
		com->redirect = 1;
	(*cur_ptr)++;
	while (is_separator(**cur_ptr))
		(*cur_ptr)++;
	while ((check = !ft_strchr(" |$><\'\"\\~#\0\n\t\r", **cur_ptr)))
		joinchar(buffer, *(*cur_ptr)++);
	redirect(com, buffer);
	if (**cur_ptr == 0 || **cur_ptr == '\n' || **cur_ptr =='#')
		(*cur_ptr)--;
	else
		new_word(buf, cur_ptr);
}

int		spec_symb(char **cur_ptr, char ***buf, t_vars *vars, t_command *com)
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
	else if (**cur_ptr == '>' || **cur_ptr == '<')
		redirect_parse(cur_ptr, com, buf);
	return (0);
}

int		parse_command(char **cur_ptr, char **buf, t_command *com, t_vars *vars)
{
	*buf = ft_calloc(BUFF_SIZE, sizeof(char));
	while (is_separator(**cur_ptr))
		(*cur_ptr)++;
	while (1)
	{
		if ((ft_strchr("\0\n", **cur_ptr) || **cur_ptr == '#') && !vars->brackets)
			break ;
		if (**cur_ptr == ';')
		{
			(*cur_ptr)++;
			return (0);
		}
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