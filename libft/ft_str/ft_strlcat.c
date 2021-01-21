/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:39:48 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/02 12:57:37 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int		dst_i;
	unsigned int		src_i;

	dst_i = 0;
	src_i = 0;
	while (dst[dst_i])
		dst_i++;
	while (src[src_i] && dst_i + src_i + 1 < dstsize)
	{
		dst[dst_i + src_i] = src[src_i];
		src_i++;
	}
	if (dstsize >= dst_i)
		dst[dst_i + src_i] = '\0';
	while (src[src_i])
		src_i++;
	if (dstsize < dst_i)
		return (src_i + dstsize);
	return (src_i + dst_i);
}
