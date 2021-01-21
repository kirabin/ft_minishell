/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:12:32 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/23 11:55:28 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		zero_precision_case(t_print *p, unsigned int arg)
{
	if (p->f.precision_given && p->f.precision == 0 && arg == 0)
	{
		ft_strfill(p->f.fill, p->f.width);
		return (1);
	}
	return (0);
}

static void		print_x_default(t_print *p, bool is_upper)
{
	unsigned int	arg;

	arg = va_arg(p->valist, unsigned int);
	if (zero_precision_case(p, arg))
		return ;
	p->f.arg_len = ft_lenui_hex(arg);
	p->f.precision -= p->f.arg_len;
	p->f.precision = p->f.precision < 0 ? 0 : p->f.precision;
	p->f.width -= p->f.precision + p->f.arg_len;
	p->f.width = p->f.width < 0 ? 0 : p->f.width;
	p->f.fill = p->f.precision_given ? ' ' : p->f.fill;
	if (p->f.precision == 0 && p->f.fill == '0')
		ft_swapi(&(p->f.precision), &(p->f.width));
	ft_strfill(p->f.fill, p->f.width * !p->f.left_aligned);
	ft_strfill('0', p->f.precision);
	ft_putui_hex_fd(arg, is_upper, 1);
	ft_strfill(p->f.fill, p->f.width * p->f.left_aligned);
	p->printed += p->f.precision + p->f.arg_len + p->f.width;
}

static void		print_xl(t_print *p, bool is_upper)
{
	unsigned long	arg;

	arg = va_arg(p->valist, unsigned int);
	if (p->f.precision_given && p->f.precision == 0 && arg == 0)
	{
		ft_strfill(p->f.fill, p->f.width);
		return ;
	}
	p->f.arg_len = ft_lenul_hex(arg);
	p->f.precision -= p->f.arg_len;
	p->f.precision = p->f.precision < 0 ? 0 : p->f.precision;
	p->f.width -= p->f.precision + p->f.arg_len;
	p->f.width = p->f.width < 0 ? 0 : p->f.width;
	p->f.fill = p->f.precision_given ? ' ' : p->f.fill;
	if (p->f.precision == 0 && p->f.fill == '0')
		ft_swapi(&(p->f.precision), &(p->f.width));
	ft_strfill(p->f.fill, p->f.width * !p->f.left_aligned);
	ft_strfill('0', p->f.precision);
	ft_putul_hex_fd(arg, is_upper, 1);
	ft_strfill(p->f.fill, p->f.width * p->f.left_aligned);
	p->printed += p->f.precision + p->f.arg_len + p->f.width;
}

void			print_x(t_print *print, bool is_upper)
{
	if (print->f.length == 'l')
		print_xl(print, is_upper);
	else if (print->f.length == 'L')
		print_x_default(print, is_upper);
	else if (print->f.length == 'h')
		print_x_default(print, is_upper);
	else if (print->f.length == 'H')
		print_x_default(print, is_upper);
	else
		print_x_default(print, is_upper);
}
