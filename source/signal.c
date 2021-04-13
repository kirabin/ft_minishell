/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 09:21:40 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/13 17:13:55 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: handle signals

void	handle_sigint(int signal_code)
{
	int	pid;
	int	status;

	pid = waitpid(-1, &status, WNOHANG);
	printf("%d", pid);
	signal_code+=0;
	if (pid == 0)
		ft_putstr_fd("^C\n", 1);
	else
	{
		ft_putendl(NULL);
		ft_putstr(PROMPT);
	}
}

void	handle_sigquit(int signal_code)
{
	int	pid;
	int	status;

	pid = waitpid(-1, &status, WNOHANG);
	printf("%d", pid);
	signal_code+=0;
	if (pid == 0)
		ft_putstr_fd("^\\Quit: 3\n", 1);
	else
	{
		ft_putendl(NULL);
		ft_putstr(PROMPT);
	}
}