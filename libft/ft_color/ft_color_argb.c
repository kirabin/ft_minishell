/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_argb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:42:17 by dmilan            #+#    #+#             */
/*   Updated: 2020/12/09 09:30:32 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_color_argb(unsigned char a, unsigned char r,
							unsigned char g, unsigned char b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}
