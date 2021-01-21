/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:13:04 by dmilan            #+#    #+#             */
/*   Updated: 2020/12/11 10:51:13 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*temp;

	node = *lst;
	if (!del || !*lst)
		return ;
	while (node)
	{
		del(node->content);
		temp = node;
		node = node->next;
		free(temp);
	}
	*lst = NULL;
}
