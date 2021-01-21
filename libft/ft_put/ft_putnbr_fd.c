/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:59:43 by dmilan            #+#    #+#             */
/*   Updated: 2020/12/09 09:30:22 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puti_fd(int n, int fd)
{
	if (0 <= n && n <= 9)
		ft_putc_fd(n + '0', fd);
	else if (n >= 10)
	{
		ft_puti_fd(n / 10, fd);
		ft_puti_fd(n % 10, fd);
	}
	else
	{
		ft_putc_fd('-', fd);
		if (n / 10)
			ft_puti_fd(-(n / 10), fd);
		ft_puti_fd(-(n % 10), fd);
	}
}

void	ft_putui_fd(unsigned int n, int fd)
{
	if (0 <= n && n <= 9)
		ft_putc_fd(n + '0', fd);
	else
	{
		ft_putui_fd(n / 10, fd);
		ft_putui_fd(n % 10, fd);
	}
}

void	ft_putui_hex_fd(unsigned int n, int is_upper, int fd)
{
	if (0 <= n && n <= 9)
		ft_putc_fd(n + '0', fd);
	else if (10 <= n && n <= 15)
	{
		if (is_upper)
			ft_putc_fd(n - 10 + 'A', 1);
		else
			ft_putc_fd(n - 10 + 'a', 1);
	}
	else
	{
		ft_putui_hex_fd(n / 16, is_upper, fd);
		ft_putui_hex_fd(n % 16, is_upper, fd);
	}
}

void	ft_putul_hex_fd(unsigned long n, int is_upper, int fd)
{
	if (0 <= n && n <= 9)
		ft_putc_fd(n + '0', fd);
	else if (10 <= n && n <= 15)
	{
		if (is_upper)
			ft_putc_fd(n - 10 + 'A', 1);
		else
			ft_putc_fd(n - 10 + 'a', 1);
	}
	else
	{
		ft_putul_hex_fd(n / 16, is_upper, fd);
		ft_putul_hex_fd(n % 16, is_upper, fd);
	}
}
