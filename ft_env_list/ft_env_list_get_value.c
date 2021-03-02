/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_list_get_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 09:40:16 by dmilan            #+#    #+#             */
/*   Updated: 2021/02/16 14:01:16 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_env_list_get_value(t_env_list *env_list, char *key)
{
	while (env_list)
	{
		if ((ft_strcmp(env_list->item->key, key)) == 0)
			return (env_list->item->value);
		env_list = env_list->next;
	}
	return (NULL);
}