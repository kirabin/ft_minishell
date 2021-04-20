/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 09:21:40 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/20 17:49:54 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signals(int signal_code)
{
	int		status;

	wait(&status);
	if (status == SIGINT || status == SIGQUIT)
	{
		if (signal_code == SIGINT)
		{
			g_errno = 130;
			ft_putendl(NULL);
		}
		else if (signal_code == SIGQUIT)
		{
			g_errno = 131;
			ft_putstr_fd("Quit: 3\n", 1);
		}
	}
	else if ((signal_code == 2 && status != 0)
		|| (signal_code != 2 && status == 0))
	{
		write(1, "\n", 1);
		ft_putprompt();
		tputs(save_cursor, 1, ft_putint);
	}
}
