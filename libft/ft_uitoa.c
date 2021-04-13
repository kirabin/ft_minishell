/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:22:54 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/13 08:29:19 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	char	*res;
	int		i;
	int		len;

	len = ft_lenui(n);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = len - 1;
	while (i >= 0)
	{
		res[i--] = (n % 10) + '0';
		n /= 10;
	}
	res[len] = '\0';
	return (res);
}
