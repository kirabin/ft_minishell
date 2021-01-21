/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_bubble_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:48:04 by dmilan            #+#    #+#             */
/*   Updated: 2020/12/11 16:54:30 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_bubble_sort(t_list **list, int (*compare)(t_list *, t_list *))
{
	t_list		*a;
	t_list		*b;

	a = *list;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (compare(a, b))
				ft_lst_swap(list, a, b);
			b = b->next;
		}
		a = a->next;
	}
}
