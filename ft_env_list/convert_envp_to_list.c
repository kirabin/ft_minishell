/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_envp_to_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 09:24:40 by dmilan            #+#    #+#             */
/*   Updated: 2021/03/02 12:28:53 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env_item	*get_env_item_from_envp_string(const char *envp_string)
{
	int			i;
	t_env_item	*item;

	i = 0;
	item = ft_env_item_new(NULL, NULL);
	while (envp_string[i] != '=')
		i++;
	item->key = ft_strndup(envp_string, i);
	envp_string += i + 1;
	item->value = ft_strdup(envp_string);
	return (item);
}

t_env_list			*convert_envp_to_list(char **envp)
{
	t_env_list	*env_list;
	t_env_item	*env_item;

	env_list = NULL;
	if (envp == NULL)
		return (NULL);
	while(*envp)
	{
		env_item = get_env_item_from_envp_string(*envp);
		ft_env_list_add_back(&env_list, ft_env_list_new(env_item));
		envp++;
	}
	return (env_list);
}
