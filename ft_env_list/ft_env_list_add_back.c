/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_list_add_back.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 09:00:35 by dmilan            #+#    #+#             */
/*   Updated: 2021/02/12 09:11:29 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_list_add_back(t_env_list **env_list, t_env_list *new)
{
	t_env_list	*node;

	node = *env_list;
	if (!*env_list)
	{
		*env_list = new;
		return ;
	}
	if (!new)
		return ;
	while (node->next)
		node = node->next;
	node->next = new;
}