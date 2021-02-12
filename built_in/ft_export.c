/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 09:47:27 by dmilan            #+#    #+#             */
/*   Updated: 2021/02/12 14:01:19 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**   Set environment variable
**    - No options
**    - Args: NAME=VALUE NAME2=VALUE2
*/


// errors ?
void	ft_export(char *key, char *value, t_env_list **env_list)
{
	t_env_item	*item;
	// no args -> ft_env_list_print_with_declare()

	if (key)
	{
		if (ft_env_key_exists(*env_list, key))
		{
			ft_env_list_replace(*env_list, key, value);
			free(key);
		}
		else
		{
			item = ft_env_item_new(key, value);
			ft_env_list_add_back(env_list, ft_env_list_new(item));
		}
	}
	else
	{
		ft_env_list_print_with_declare(*env_list);
	}
}