/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_is_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:57:23 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/07 14:28:11 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_string_is_path(char *string)
{
	if (ft_string_is_absolute_path(string)
		|| ft_string_is_relative_path(string))
		return (true);
	return (false);
}

bool	ft_string_is_absolute_path(char *string)
{
	if (string[0] == '/')
		return (true);
	return (false);
}

bool	ft_string_is_relative_path(char *string)
{
	if (string[0] != '/' && ft_strchr(string, '/'))
		return (true);
	return (false);
}
