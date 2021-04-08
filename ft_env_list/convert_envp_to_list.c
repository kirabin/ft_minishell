/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_envp_to_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 09:24:40 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/07 14:52:30 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	which_identifier(const char *str)
{
	if (!str)
		return (0);
	if (*str == '=')
		return (1);
	if (*str == '+' && *(str + 1) == '=')
		return (2);
	if (*str == '+')
		return (-1);
	return (0);
}

t_env_item	*get_env_item_from_envp_string(const char *envp_string)
{
	int			i;
	t_env_item	*item;

	item = ft_env_item_new(NULL, 0, NULL);
	i = find_name_len(envp_string);
	item->key = ft_strndup(envp_string, i);
	item->identifier = which_identifier(envp_string + i);
	item->value = ft_strdup(envp_string + item->identifier);
	return (item);
}

t_env_list	*convert_envp_to_list(char **envp)
{
	t_env_list	*env_list;
	t_env_item	*env_item;

	env_list = NULL;
	if (envp == NULL)
		return (NULL);
	while (*envp)
	{
		env_item = get_env_item_from_envp_string(*envp);
		ft_env_list_add_back(&env_list, ft_env_list_new(env_item));
		envp++;
	}
	return (env_list);
}
