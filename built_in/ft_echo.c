/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 09:47:10 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/07 14:21:32 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool		is_suppressed_option(char *str)
{
	if (ft_strcmp(str, "-n") == 0)
		return (true);
	return (false);
}

int		ft_echo(char **args)
{
	bool	is_suppressed;

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
	return (1);  // TODO: do I need return?
}
