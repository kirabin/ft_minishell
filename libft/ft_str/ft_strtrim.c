/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:03:07 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/05 18:17:45 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	int		i;

	i = 0;
	if (!set)
		return (0);
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		len;
	int		start;
	int		end;
	int		i;

	start = 0;
	if (!s1)
		return (0);
	len = ft_strlen((char *)s1);
	while (s1[start] && in_set(s1[start], set))
		start++;
	end = len - 1;
	while (end >= start && s1[end] && len > 0 && in_set(s1[end], set))
		end--;
	res = malloc(end - start + 2);
	if (!res)
		return (0);
	i = start - 1;
	while (++i <= end)
		res[i - start] = s1[i];
	res[end - start + 1] = '\0';
	return (res);
}
