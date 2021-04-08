/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:17:22 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/08 12:24:07 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, const char *s2)
{
	int		s1_len;
	int		s2_len;
	int		s1_i;
	int		s2_i;
	char	*res;

	s1_i = 0;
	s2_i = 0;
	if (!s2)
		return (s1);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	res = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!res)
		return (s1);
	while (s2_i < s1_len)
		res[s1_i++] = s1[s2_i++];
	s2_i = 0;
	while (s2_i < s2_len)
		res[s1_i++] = s2[s2_i++];
	res[s1_i] = '\0';
	free(s1);
	return (res);
}

char	*ft_strjoin_free_rev(const char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	int		s1_i;
	int		s2_i;
	char	*res;

	s1_i = 0;
	s2_i = 0;
	if (!s1)
		return (s2);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	res = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!res)
		return (s2);
	while (s2_i < s1_len)
		res[s1_i++] = s1[s2_i++];
	s2_i = 0;
	while (s2_i < s2_len)
		res[s1_i++] = s2[s2_i++];
	res[s1_i] = '\0';
	free(s2);
	return (res);
}

char	*ft_strjoin_free_free(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	int		s1_i;
	int		s2_i;
	char	*res;

	s1_i = 0;
	s2_i = 0;
	if (!s2)
		return (s1);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	res = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!res)
		return (s1);
	while (s2_i < s1_len)
		res[s1_i++] = s1[s2_i++];
	s2_i = 0;
	while (s2_i < s2_len)
		res[s1_i++] = s2[s2_i++];
	res[s1_i] = '\0';
	free(s1);
	free(s2);
	return (res);
}
