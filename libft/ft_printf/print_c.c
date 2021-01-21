/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:12:40 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/23 11:55:51 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	- Doesn't get affected by length
*/

void	print_c(t_print *print)
{
	unsigned char	arg;

	arg = (unsigned char)va_arg(print->valist, int);
	print->f.arg_len = 1;
	if (print->f.left_aligned)
	{
		ft_putuc_fd(arg, 1);
		ft_strfill(print->f.fill, print->f.width - print->f.arg_len);
	}
	else
	{
		ft_strfill(print->f.fill, print->f.width - print->f.arg_len);
		ft_putuc_fd(arg, 1);
	}
	print->printed += ft_max(print->f.width, print->f.arg_len);
}
