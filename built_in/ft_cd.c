/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 09:46:52 by dmilan            #+#    #+#             */
/*   Updated: 2021/02/07 13:05:54 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**   Change Directory
*/

int		ft_cd(const char *new_path)
{
	if (chdir(new_path) == -1)
	{
		// error
		ft_putstr_fd(strerror(errno), 2);
	}
	return (1);
}