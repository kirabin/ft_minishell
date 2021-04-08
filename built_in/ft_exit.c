/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 09:47:24 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/07 14:55:35 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**   Stop execution of program
**    - no options
**		exit: exit [n]
**		Exit the shell with a status of N.  If N is omitted, the exit status
**		is that of the last command executed.
*/

// MAN — https://man7.org/linux/man-pages/man3/exit.3.html

/*
 *	Cases:
 *	- exit 2147483647   - 255
 *	- exit 2147483648   - 0
 *	- exit 2147483649   - 1
*/

static void	numeric_arg_error(char *str)
{
	ft_putstr_fd("exit: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': numeric argument required\n", 2);
}

void	ft_exit(char *arg)
{
	long long	code;

	if (!*arg)
		exit(errno);
	ft_putstr_fd("error\n", 2);
	if (is_long_long(arg))
	{
		code = ft_atoi_long_long(arg);
		exit(code & 0xFF);
	}
	else
	{
		numeric_arg_error(arg);
		exit(255);
	}
}
