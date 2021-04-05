/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 09:46:52 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/03 16:03:16 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**   Change Directory
*/

int		ft_cd(const char *new_path, t_env_list *list)
{
	if (new_path == NULL)
		new_path = ft_env_list_get_value(list, "HOME");
	if (chdir(new_path) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
	}
	return (1);
}