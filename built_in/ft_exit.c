/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 09:47:24 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/13 08:46:54 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// extern int errno;

/*
**	SUBJECT
**		- No options
**		- Like in bash
**
**	ARGS
**		- Exit the shell with a status of N.  If N is omitted, the exit status
**			is that of the last command executed.
**		- Can't have multiple errors
**		- Can't have number outside long long
*/

static void	numeric_arg_error(char *str)
{
	ft_putstr_fd("exit: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': numeric argument required\n", 2);
	g_errno = 1;
}

static void	too_many_args_error(void)
{
	ft_putstr_fd("exit: too many arguments\n", 2);
	g_errno = 1;
}

static int	charpp_len(char **args)
{
	int	len;

	len = 0;
	while (args[len])
		len++;
	return (len);
}

void	ft_exit(char **args)
{
	long long	code;

	ft_putstr_fd("exit\n", 2);
	if (charpp_len(args) > 1)
	{
		too_many_args_error();
		return ;
	}
	if (!*args)
		exit(g_errno); // TODO: g_errno is not finished fully
	if (is_long_long(*args))
	{
		code = ft_atoi_long_long(*args);
		exit(code & 0xFF);
	}
	else
	{
		numeric_arg_error(*args);
		exit(255);
	}
}
