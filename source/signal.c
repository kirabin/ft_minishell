/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 09:21:40 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/16 18:21:19 by dmilan           ###   ########.fr       */
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
			ft_putendl(NULL);
		}
	}
	else
	{
			ft_putendl(NULL);
			ft_putprompt();
	}
}

// TODO: find where g_errno is getting replaces to 0
