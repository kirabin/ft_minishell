/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_item_with_key.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:11:20 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/07 09:11:41 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_item	*ft_get_env_item_with_key(t_env_list *list, char *key)
{
	while (list)
	{
		if (ft_strcmp(list->item->key, key) == 0)
			return (list->item);
		list = list->next;
	}
	return (NULL);
}