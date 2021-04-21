/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:04:54 by msamual           #+#    #+#             */
/*   Updated: 2021/04/21 12:30:55 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unexpected_token(char *str)
{
	while (is_separator(*str))
		str++;
	if (*str == '|' && *(str + 1) == '|')
		return (puterror("syntax error near unexpected token `||'", 258));
	else if (*str == ';' && *(str + 1) == ';')
		return (puterror("syntax error near unexpected token `;;'", 258));
	else if (*str == '|')
		return (puterror("syntax error near unexpected token `|'", 258));
	else if (*str == ';')
		return (puterror("syntax error near unexpected token `;'", 258));
	return (0);
}

int	check(char *str)
{
	while (*str && is_separator(*str))
		str++;
	if (*str == '|' || *str == ';')
		return (unexpected_token(str));
	return (0);
}

int	check_redirect_unex_token(char *str)
{
	char	token[2];

	if (*str == '>' && *(str + 1) == '>')
		str += 2;
	else
		str++;
	while (is_separator(*str))
		str++;
	if (*str == '\n' || *str == '\0' || *str == '#')
		return (puterror("syntax error near unexpected token `newline'", 258));
	else if (ft_strchr("|;<>&", *str))
	{
		token[0] = *str;
		token[1] = 0;
		return (puterror_three("syntax error near unexpected token `"
				, token, "\'", 258));
	}
	return (0);
}

int	check_unexpected_token(char *str)
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
				return (puterror("Error: unknown use of pipes!", 258));
			if (check(str))
				return (-1);
		}
		else if (*str == '>' || *str == '<')
		{
			if (check_redirect_unex_token(str))
				return (-1);
		}
		str++;
	}
	return (0);
}

int	check_brackets(char *str)
{
	while (*str)
	{
		if (*str == '\'')
		{
			str++;
			while (*str != '\'')
			{
				if (*str == '\0' || *str == '\n')
					return (puterror("syntax error: unclosed quotes", 1));
				str++;
			}
		}
		if (*str == '\"')
		{
			str++;
			while (*str != '\"')
			{
				if (*str == '\0' || *str == '\n')
					return (puterror("syntax error: unclosed quotes", 1));
				str++;
			}
		}
		str++;
	}
	return (0);
}
