/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 09:47:10 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/16 18:36:57 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	SUBJECT
**		- Option -n at the start
**		- Like in bash
**
**	ARGS
**		- Ignores arguments
**
**	OPTIONS / FLAGS
**		-[n] Do not output the trailing newline
**
**	EXIT STATUS
**		-[0] Successful completion.
**		-[>0] An error occurred.
*/

static bool	is_suppressed_option(char *str)
{
	if (ft_strcmp(str, "-n") == 0)
		return (true);
	return (false);
}

void	ft_echo(char **args)
{
	bool	is_suppressed;

	if (!args)
	{
		ft_putc_fd('\n', 1);
		return ;
	}
	is_suppressed = is_suppressed_option(*args);
	while (*args)
	{
		ft_putstr_fd(*args, 1);
		args++;
		if (*args)
			ft_putc_fd(' ', 1);
	}
	if (!is_suppressed)
		ft_putc_fd('\n', 1);
	g_errno = 0;
}
