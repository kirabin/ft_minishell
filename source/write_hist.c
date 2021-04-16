/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:24:22 by msamual           #+#    #+#             */
/*   Updated: 2021/04/16 18:20:47 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	write_history(t_vars *vars)
{
	t_history	*tmp;
	int			fd;

	fd = open(".history.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	tmp = vars->history;
	while (tmp && tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		write(fd, tmp->com, ft_strlen(tmp->com));
		write(fd, "\n", 1);
		tmp = tmp->next;
	}
	close(fd);
}

void	ctrl_d(t_vars *vars)
{
	if (ft_strlen(vars->history->com))
		return ;
	remove_elem_hist(&(vars->history));
	write_history(vars);
	write(1, "exit\n", 5);
	exit(0);
}
