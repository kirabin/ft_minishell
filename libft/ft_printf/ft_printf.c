/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:56:21 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/23 11:45:15 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*format_flags(t_print *print, const char *format_string)
{
	if (*format_string == '-')
	{
		print->f.left_aligned = 1;
		print->f.fill = ' ';
	}
	else if (*format_string == '0')
		print->f.fill = print->f.left_aligned ? ' ' : '0';
	else if (*format_string == ' ')
		print->f.sign = ' ';
	else if (*format_string == '+')
		print->f.sign = '+';
	else if (*format_string == '*')
	{
		print->f.width = va_arg(print->valist, int);
		if (print->f.width < 0)
		{
			print->f.left_aligned = 1;
			print->f.fill = ' ';
			print->f.width *= -1;
		}
	}
	return (format_string);
}

static const char	*format_precision(t_print *print, const char *format_string)
{
	print->f.precision_given = 1;
	if (*(format_string + 1) == '*')
	{
		print->f.precision = va_arg(print->valist, int);
		format_string++;
	}
	else
	{
		print->f.precision = ft_atoi(++format_string);
		format_string = ft_strskip(format_string, ft_isdigit) - 1;
	}
	return (format_string);
}

static const char	*strip_format(t_print *print, const char *format_string)
{
	while (*format_string && !print->f.type)
	{
		if (ft_strchr("-0 +*", *format_string))
			format_string = format_flags(print, format_string);
		else if (ft_isdigit(*format_string))
		{
			print->f.width = ft_atoi(format_string);
			format_string = ft_strskip(format_string, ft_isdigit) - 1;
		}
		else if (*format_string == '.')
			format_string = format_precision(print, format_string);
		else if (ft_strchr("lh", *format_string))
			format_string = get_f_length(print, format_string);
		else if (ft_strchr("cspdiuxXnfge%", *format_string))
			print->f.type = *format_string;
		else
			break ;
		format_string++;
	}
	return (format_string);
}

static int			print_format(t_print *print)
{
	bool flag;

	flag = 1;
	if (print->f.type == 'c')
		print_c(print);
	else if (print->f.type == 's')
		print_s(print);
	else if (print->f.type == 'p')
		print_p(print);
	else if (print->f.type == 'd' || print->f.type == 'i')
		flag = print_di(print);
	else if (print->f.type == 'u')
		flag = print_u(print);
	else if (print->f.type == 'x')
		print_x(print, 0);
	else if (print->f.type == 'X')
		print_x(print, 1);
	else if (print->f.type == '%')
		print_percent(print);
	return (flag);
}

int					ft_printf(const char *format_string, ...)
{
	t_print		print;

	print = default_print();
	va_start(print.valist, format_string);
	if (!format_string)
		return (0);
	while (*format_string)
	{
		if (*format_string == '%')
		{
			print.f = default_format();
			format_string = strip_format(&print, ++format_string);
			if (!print_format(&print))
				return (-1);
		}
		else
		{
			ft_putc_fd(*format_string, 1);
			print.printed++;
			format_string++;
		}
	}
	va_end(print.valist);
	return (print.printed);
}
