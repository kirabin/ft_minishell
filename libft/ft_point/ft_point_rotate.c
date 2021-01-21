/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:24:22 by dmilan            #+#    #+#             */
/*   Updated: 2020/12/07 18:24:52 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_point		ft_point_rotate(t_point point, double angle)
{
	t_point	result;

	result.x = point.x * cos(angle) - point.y * sin(angle);
	result.y = point.x * sin(angle) + point.y * cos(angle);
	return (result);
}
