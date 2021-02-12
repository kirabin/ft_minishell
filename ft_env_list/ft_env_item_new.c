/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_item_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:06:39 by dmilan            #+#    #+#             */
/*   Updated: 2021/02/12 10:06:48 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_item	*ft_env_item_new(char *key, char *value)
{
	t_env_item	*item;

	if (!(item = malloc(sizeof(t_env_item))))
		return (NULL);
	item->key = key;
	item->value = value;
	return (item);
}