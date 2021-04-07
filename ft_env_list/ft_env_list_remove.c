/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_list_remove.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:53:10 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/07 14:50:02 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_env_list_remove(t_env_list **list, char *key)
{
	t_env_list	*node;
	t_env_list	*temp;
	t_env_list	*prev;

	node = *list;
	prev = NULL;
	while (node)
	{
		if (ft_strcmp(node->item->key, key) == 0)
		{
			ft_env_item_del(node->item);
			temp = node;
			if (prev)
				prev->next = node->next;
			else
				*list = node->next;
			free(temp);
			return (true);
		}
		prev = node;
		node = node->next;
	}
	return (false);
}
