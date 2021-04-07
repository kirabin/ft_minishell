/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:30:31 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/07 14:25:59 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	index;
	int				comp_value;

	index = 0;
	while (s1[index] || s2[index])
	{
		comp_value = (unsigned char)s1[index] - (unsigned char)s2[index];
		if (comp_value)
			return (comp_value);
		index++;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	index;
	int				comp_value;

	index = 0;
	while ((s1[index] || s2[index]) && index < n)
	{
		comp_value = (unsigned char)s1[index] - (unsigned char)s2[index];
		if (comp_value)
			return (comp_value);
		index++;
	}
	return (0);
}
