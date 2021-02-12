/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_list_remove.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:53:10 by dmilan            #+#    #+#             */
/*   Updated: 2021/02/12 10:57:04 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	list_item_compare(t_env_item *src, t_env_item *ref)
{
	return (0);
}

void	ft_env_list_remove(t_env_list **list, t_env_item *reference)
{
	t_env_list *node;
	
	node = *list;
	while (node)
	{
		if (list_item_compare(node, reference) == 0)
		{
			
		}
		node = node->next;
	}
}