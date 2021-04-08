/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_list_replace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:39:15 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/07 14:49:48 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_list_replace(t_env_list *list, char *key, char *new_value)
{
	while (list)
	{
		if (ft_strcmp(list->item->key, key) == 0)
		{
			free(list->item->value);
			list->item->value = ft_strdup(new_value);
			break ;
		}
		list = list->next;
	}
}
