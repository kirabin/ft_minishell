/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:43:20 by dmilan            #+#    #+#             */
/*   Updated: 2020/12/07 18:44:59 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color		ft_color_new(unsigned char a, unsigned char r,
						unsigned char g, unsigned char b)
{
	t_color		new;

	new.a = a;
	new.r = r;
	new.g = g;
	new.b = b;
	new.argb = ft_color_argb(a, r, g, b);
	return (new);
}
