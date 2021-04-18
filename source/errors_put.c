/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:48:53 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/17 13:49:49 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	puterror(char *msg, int code)
{
	if (!msg)
		msg = strerror(code);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	g_errno = code;
	return (code);
}

int	puterror_three(char *s1, char *s2, char *s3, int code)
{
	write(2, s1, ft_strlen(s1));
	write(2, s2, ft_strlen(s2));
	write(2, s3, ft_strlen(s3));
	write(2, "\n", 1);
	g_errno = code;
	return (code);
}
