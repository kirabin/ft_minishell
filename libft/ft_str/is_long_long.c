/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_long_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:02:02 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/07 14:20:47 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_long_long(char *str)
{
	long long	res;
	int			sign;
	char		c;

	res = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '+') * 2 - 1;
	while (*str && ft_isdigit(*str))
	{
		c = *str++ - '0';
		if (sign == 1 && res > LLONG_MAX / 10)
			return (false);
		if (sign == 1 && res == LLONG_MAX / 10 && c > 7)
			return (false);
		if (sign == -1 && res < LLONG_MIN / 10)
			return (false);
		if (sign == -1 && res == LLONG_MIN / 10 && c > 8)
			return (false);
		res = res * 10 + c * sign;
	}
	return (true);
}
