/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:53:07 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/23 11:55:42 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_p(t_print *p)
{
	long	arg;
	void	*arg_p;

	arg_p = va_arg(p->valist, void *);
	arg = (long)arg_p;
	if (p->f.precision_given && p->f.precision == 0 && arg == 0)
	{
		ft_strfill(p->f.fill, p->f.width);
		return ;
	}
	p->f.arg_len = ft_lenul_hex(arg) + 2;
	p->f.precision -= p->f.arg_len;
	p->f.precision = p->f.precision < 0 ? 0 : p->f.precision;
	p->f.width -= p->f.precision + p->f.arg_len;
	p->f.width = p->f.width < 0 ? 0 : p->f.width;
	p->f.fill = p->f.precision_given ? ' ' : p->f.fill;
	if (p->f.precision == 0 && p->f.fill == '0')
		ft_swapi(&(p->f.precision), &(p->f.width));
	ft_strfill(p->f.fill, p->f.width * !p->f.left_aligned);
	ft_strfill('0', p->f.precision);
	ft_putstr_fd("0x", 1);
	ft_putul_hex_fd(arg, 0, 1);
	ft_strfill(p->f.fill, p->f.width * p->f.left_aligned);
	p->printed += p->f.precision + p->f.arg_len + p->f.width;
}
