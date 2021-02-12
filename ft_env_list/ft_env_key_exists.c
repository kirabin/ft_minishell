/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_key_exists.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:59:18 by dmilan            #+#    #+#             */
/*   Updated: 2021/02/12 12:36:23 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_env_key_exists(t_env_list *list, char *key)
{
	while (list)
	{
		if (ft_strcmp(list->item->key, key) == 0)
			return (true);
		list = list->next;
	}
	return (false);
}