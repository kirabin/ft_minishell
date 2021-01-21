/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:10:17 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/13 12:41:02 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		len;
	int		sign;

	len = ft_leni(n);
	res = malloc(len + 1);
	if (!res)
		return (0);
	i = len - 1;
	sign = 1;
	if (n < 0)
		sign = -1;
	while (i >= 0)
	{
		res[i--] = (n % 10) * sign + '0';
		n /= 10;
	}
	if (sign == -1)
		res[0] = '-';
	res[len] = '\0';
	return (res);
}
