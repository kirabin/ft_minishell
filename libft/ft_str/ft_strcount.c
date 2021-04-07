/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:02:18 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/07 14:29:28 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcount(const char *s, char c)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
		if (*s++ == c)
			count++;
	return (count);
}
