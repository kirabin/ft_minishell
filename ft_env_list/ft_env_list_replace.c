/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_list_replace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:39:15 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/08 16:51:08 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_list_replace(t_env_list *list, t_env_item *new_item)
{
	while (list)
	{
		if (ft_strcmp(list->item->key, new_item->key) == 0)
		{
			free(list->item->value);
			list->item->value = ft_strdup(new_item->value);
			list->item->identifier = new_item->identifier;
			break ;
		}
		list = list->next;
	}
}
