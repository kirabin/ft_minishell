/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:42:23 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/13 08:44:15 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (true)
	{
		if (s[i] == c)
			return ((char *)s + i);
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return (NULL);
}
