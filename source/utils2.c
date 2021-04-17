/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 12:03:02 by msamual           #+#    #+#             */
/*   Updated: 2021/04/17 12:16:51 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	new_word(char ***buf, char **cur_ptr)
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
