/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:30:31 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/07 14:30:15 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') * 2 - 1;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
		if (res * sign > 2147483647)
			return (-1);
		if (res * sign < -2147483648)
			return (0);
	}
	return (res * sign);
}

long long	ft_atoi_long_long(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '+') * 2 - 1;
	while (*str && ft_isdigit(*str))
		res = res * 10 + (*str++ - '0') * sign;
	return (res);
}
