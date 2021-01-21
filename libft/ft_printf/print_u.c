/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:02:48 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/23 11:55:06 by dmilan           ###   ########.fr       */
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

int				print_u(t_print *p)
{
	unsigned int	arg;

	arg = va_arg(p->valist, unsigned int);
	if (zero_precision_case(p, arg))
		return (1);
	if (!(p->f.arg_s = ft_uitoa(arg)))
		return (0);
	p->f.arg_len = ft_strlen(p->f.arg_s);
	p->f.precision -= p->f.arg_len;
	p->f.precision = p->f.precision < 0 ? 0 : p->f.precision;
	p->f.width -= p->f.precision + p->f.arg_len;
	p->f.width = p->f.width < 0 ? 0 : p->f.width;
	p->f.fill = p->f.precision_given ? ' ' : p->f.fill;
	if (p->f.precision == 0 && p->f.fill == '0')
		ft_swapi(&(p->f.precision), &(p->f.width));
	ft_strfill(p->f.fill, p->f.width * !p->f.left_aligned);
	ft_strfill('0', p->f.precision);
	ft_putstr_fd(p->f.arg_s, 1);
	ft_strfill(p->f.fill, p->f.width * p->f.left_aligned);
	p->printed += p->f.precision + p->f.arg_len + p->f.width;
	free(p->f.arg_s);
	return (1);
}
