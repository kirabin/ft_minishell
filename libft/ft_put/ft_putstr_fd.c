/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:24:30 by dmilan            #+#    #+#             */
/*   Updated: 2020/12/09 09:27:58 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == 0)
		return ;
	while (*s)
		ft_putc_fd(*s++, fd);
}

void	ft_putstrn_fd(char *s, int n, int fd)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (s[i] && i < n)
	{
		ft_putc_fd(s[i], fd);
		i++;
	}
}
