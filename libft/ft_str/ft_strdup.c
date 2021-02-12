/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:47:55 by dmilan            #+#    #+#             */
/*   Updated: 2021/02/12 08:58:50 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen((char *)s1);
	res = malloc(sizeof(char) * (len + 1));
	if (!res || !s1)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strndup(const char *s1, int n)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen((char *)s1);
	res = malloc(sizeof(char) * (len + 1));
	if (!res || !s1)
		return (NULL);
	while (s1[i] && i < n)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
