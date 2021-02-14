/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_name_from_path.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 10:04:06 by dmilan            #+#    #+#             */
/*   Updated: 2021/02/14 10:11:14 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_file_name_from_path(char *path)
{
	char	*file_name;

	file_name = path;
	while (*path)
	{
		if (*path++ == '/')
			file_name = path;
	}
	return (file_name);
}
