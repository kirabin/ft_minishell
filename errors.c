/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:04:54 by msamual           #+#    #+#             */
/*   Updated: 2021/04/07 14:45:17 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unexpected_token(char *token)
{
	if (*token == '|' && *(token + 1) != '|')
		return (puterror("syntax error near unexpected token `|'", 258));
	if (*token == ';' && *(token + 1) != ';')
		return (puterror("syntax error near unexpected token `;'", 258));
	if (*token == '|' && *(token + 1) == '|')
		return (puterror("syntax error near unexpected token `||'", 258));
	if (*token == ';' && *(token + 1) == ';')
		return (puterror("syntax error near unexpected token `;;'", 258));
	return (0);
}

int	puterror(char *msg, int code)
{
	errno = code;
	write(2, msg, ft_strlen(msg));
	return (code);
}
