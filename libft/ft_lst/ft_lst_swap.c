/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:24:03 by dmilan            #+#    #+#             */
/*   Updated: 2020/12/11 16:35:17 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*find_prev(t_list **head, t_list *node)
{
	t_list		*prev;

	prev = *head;
	while (prev->next)
	{
		if (prev->next->content == node->content)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}

void			ft_lst_swap(t_list **head, t_list *a, t_list *b)
{
	t_list		*prev_a;
	t_list		*prev_b;
	t_list		*temp;

	if (a->content == b->content || a == NULL || b == NULL || head == NULL ||
		*head == NULL)
		return ;
	prev_a = find_prev(head, a);
	prev_b = find_prev(head, b);
	if (prev_a == NULL)
		*head = b;
	else
		prev_a->next = b;
	if (prev_b == NULL)
		*head = a;
	else
		prev_b->next = a;
	temp = a->next;
	a->next = b->next;
	b->next = temp;
}
