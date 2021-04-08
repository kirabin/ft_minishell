/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:07:18 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/07 14:27:17 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*res;
	int		i;

	i = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin_three(char const *s1, char const *s2, char const *s3)
{
	int		len;
	char	*res;
	int		i;

	i = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + ft_strlen((char *)s3);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	while (*s3)
		res[i++] = *s3++;
	res[i] = '\0';
	return (res);
}
