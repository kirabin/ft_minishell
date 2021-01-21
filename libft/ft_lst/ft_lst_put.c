/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:43:39 by dmilan            #+#    #+#             */
/*   Updated: 2020/12/11 16:54:18 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lst_put(t_list *list, void (*put)(void *content))
{
	if (!list)
	{
		ft_printf("list is empty\n");
		return ;
	}
	if (!put)
	{
		ft_printf("function is empty\n");
		return ;
	}
	while (list)
	{
		put(list->content);
		list = list->next;
	}
	ft_printf("\n");
}
