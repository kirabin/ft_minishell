/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 09:31:06 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/02 12:41:23 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int			i;
	unsigned char			*d;
	const unsigned char		*s;

	i = 0;
	d = dst;
	s = src;
	while (i < n && s != d)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
