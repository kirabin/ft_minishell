/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_list_clear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 09:18:54 by dmilan            #+#    #+#             */
/*   Updated: 2021/02/12 09:22:55 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	del(t_env_item *item)
{
	free(item->key);
	free(item->value);
}

void	ft_env_list_clear(t_env_list **lst)
{
	t_env_list	*node;
	t_env_list	*temp;

	node = *lst;
	if (!*lst)
		return ;
	while (node)
	{
		del(node->item);
		free(node->item);
		temp = node;
		node = node->next;
		free(temp);
	}
	*lst = NULL;
}