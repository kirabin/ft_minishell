/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:03:07 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/16 15:42:06 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = start;
	while (s1[end])
		end++;
	while (end && ft_strchr(set, s1[end]))
		end--;
	if (end < start)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start + 1));
}