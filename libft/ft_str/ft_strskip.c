/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strskip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:39:26 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/19 16:45:04 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char		*ft_strskip(const char *s, int (*is_that)(int))
{
	if (!s || !is_that)
		return (s);
	while (*s && is_that(*s))
	{
		s++;
	}
	return (s);
}
