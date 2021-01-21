/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:35:23 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/23 11:55:38 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_percent(t_print *print)
{
	print->f.arg_len = 1;
	if (print->f.left_aligned)
	{
		ft_putc_fd('%', 1);
		ft_strfill(' ', print->f.width - print->f.arg_len);
	}
	else
	{
		ft_strfill(print->f.fill, print->f.width - print->f.arg_len);
		ft_putc_fd('%', 1);
	}
	print->printed += ft_max(print->f.width, print->f.arg_len);
}
