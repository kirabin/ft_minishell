/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_list_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 09:32:22 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/08 15:13:05 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_list_print(t_env_list *env_list)
{
	while (env_list != NULL)
	{
		if (env_list->item->identifier == 0)
		{
			env_list = env_list->next;
			continue ;
		}
		ft_putstr_fd(env_list->item->key, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(env_list->item->value, 1);
		ft_putstr_fd("\n", 1);
		env_list = env_list->next;
	}
}

static	t_env_list	*find_prev(t_env_list **head, t_env_list *node)
{
	t_env_list		*prev;

	prev = *head;
	while (prev->next)
	{
		if (prev->next->item == node->item)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}

void	ft_env_list_swap(t_env_list **head, t_env_list *a, t_env_list *b)
{
	t_env_list		*prev_a;
	t_env_list		*prev_b;
	t_env_list		*temp;

	if (a->item == b->item || a == NULL || b == NULL || head == NULL
		|| *head == NULL)
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

static t_env_list	*sort_list_by_ascii(t_env_list *list)
{
	t_env_list	*new_list;
	t_env_list	*a;
	t_env_list	*b;
	t_env_item	*temp;

	new_list = ft_env_list_copy(list);
	a = new_list;
	while (a)
	{
		b = new_list;
		while (b->next)
		{
			if (ft_strcmp(b->item->key, b->next->item->key) > 0)
			{
				temp = b->item;
				b->item = b->next->item;
				b->next->item = temp;
			}
			b = b->next;
		}
		a = a->next;
	}
	return (new_list);
}

void	ft_env_list_print_with_declare(t_env_list *env_list)
{
	t_env_list	*sorted_list;
	t_env_list	*sorted_list_start;

	sorted_list = sort_list_by_ascii(env_list);
	sorted_list_start = sorted_list;
	while (sorted_list != NULL)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(sorted_list->item->key, 1);
		if (sorted_list->item->identifier == 0)
		{
			ft_putc_fd('\n', 1);
			sorted_list = sorted_list->next;
			continue ;
		}
		ft_putstr_fd("=\"", 1);
		ft_putstr_fd(sorted_list->item->value, 1);
		ft_putstr_fd("\"\n", 1);
		sorted_list = sorted_list->next;
	}
	ft_env_list_clear(&sorted_list_start);
}
