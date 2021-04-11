/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_item_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:06:39 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/11 17:42:05 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_item	*ft_env_item_new(char *key, int identifier, char *value)
{
	t_env_item	*item;

	item = malloc(sizeof(t_env_item));
	if (!item)
		exit(1); // TODO: should we print the message? which code to pass?
	item->key = key;
	item->identifier = identifier;
	item->value = value;
	return (item);
}
