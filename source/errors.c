/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:04:54 by msamual           #+#    #+#             */
/*   Updated: 2021/04/13 18:51:56 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int		unexpected_token(char *str)
{
	while (is_separator(*str))
		str++;
	if (*str == '|' && *(str + 1) == '|')
		return (puterror("syntax error near unexpected token `||'\n", 258));
	else if (*str == ';' && *(str + 1) == ';')
		return (puterror("syntax error near unexpected token `;;'\n", 258));
	else if (*str == '|')
		return (puterror("syntax error near unexpected token `|'\n", 258));
	else if (*str == ';')
		return (puterror("syntax error near unexpected token `;'\n", 258));
	return (0);
}

int		check(char *str)
{
	while (*str && is_separator(*str))
		str++;
	if (*str == '|' || *str == ';')
		return (unexpected_token(str));
	return (0);
}

int		check_unexpected_token(char *str)
{
	while (is_separator(*str))
		str++;
	if (*str == '|' || *str == ';')
		return (unexpected_token(str));
	while (!ft_strchr("\0\n#", *str))
	{
		if (*str == '|' || *str == ';')
		{
			str++;
			if (*(str - 1) == '|' && ft_strchr("\0\n#", *str))
				return (puterror("Error: unknown use of pipes!\n", 258));
			if (check(str))
				return (-1);
		}
		str++;
	}
	return (0);
}

int		check_brackets(char *str)
{
	while (*str)
	{
		if (*str == '\'')
		{
			str++;
			while (*str != '\'')
			{
				if (*str == '\0' || *str == '\n')
					return (puterror("syntax error: unclosed quotes\n", 1));
				str++;
			}
		}
		if (*str == '\"')
		{
			str++;
			while (*str != '\"')
			{
				if (*str == '\0' || *str == '\n')
					return (puterror("syntax error: unclosed quotes\n", 1));
				str++;
			}
		}
		str++;
	}
	return (0);
}

int	puterror(char *msg, int code)
{
	write(2, msg, ft_strlen(msg));
	g_errno = code;
	return (code);
}
