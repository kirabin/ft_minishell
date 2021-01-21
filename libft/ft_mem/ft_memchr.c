/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:11:19 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/02 12:44:33 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int		i;
	unsigned char		*p;

	i = 0;
	p = (unsigned char*)s;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
