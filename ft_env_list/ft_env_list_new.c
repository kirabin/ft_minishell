/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_list_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 08:40:59 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/13 08:23:58 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_list	*ft_env_list_new(t_env_item *env_item)
{
	t_env_list	*node;

	node = malloc(sizeof(t_env_list));
	if (!node)
		return (NULL);
	node->item = env_item;
	node->next = 0;
	return (node);
}
