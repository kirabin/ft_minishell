/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_support.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:56:38 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/23 11:44:47 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_format		default_format(void)
{
	t_format f;

	f.arg_len = 0;
	f.arg_s = NULL;
	f.width = 0;
	f.precision = 0;
	f.precision_given = 0;
	f.left_aligned = 0;
	f.alternate_form = 0;
	f.fill = ' ';
	f.sign = '\0';
	f.type = '\0';
	f.length = '\0';
	return (f);
}

t_print			default_print(void)
{
	t_print		print;

	print.printed = 0;
	return (print);
}

const char		*get_f_length(t_print *print, const char *format_string)
{
	print->f.length = *format_string;
	if (ft_strchr("lh", *(format_string + 1)))
	{
		format_string++;
		print->f.length = (*format_string == 'l') ? 'L' : print->f.length;
		print->f.length = (*format_string == 'h') ? 'H' : print->f.length;
	}
	return (format_string);
}
