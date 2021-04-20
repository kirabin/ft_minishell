/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 09:47:27 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/17 11:56:59 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	SUBJECT
**		- No options
**		- Like in bash
**
**	ARGS
**		- Export arguments one by one
**
**	EXIT STATUS
**		-[0] All name operands were successfully exported.
**		-[>0] At least one name could not be exported
*/

static void	identifier_error(char *str)
{
	ft_putstr_fd("export: `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	g_errno = 1;
}

static bool	create_new_env_arg(char *key, int identifier,
	char *value, t_env_list **env_list)
{
	t_env_item	*new_item;
	t_env_list	*new_list;

	new_item = ft_env_item_new(key, identifier, value);
	if (!new_item)
		return (false);
	new_list = ft_env_list_new(new_item);
	if (!new_list)
	{
		ft_env_item_free(new_item);
		return (false);
	}
	ft_env_list_add_back(env_list, new_list);
	return (true);
}

static void	key_exists_case(t_env_list **env_list, t_env_item *item)
{
	t_env_item	*tmp_item;

	if (item->identifier == 1)
		ft_env_list_replace(*env_list, item);
	else if (item->identifier == 2)
	{
		tmp_item = ft_get_env_item_with_key(*env_list, item->key);
		tmp_item->value = ft_strjoin_free(tmp_item->value,
				item->value);
	}
	else if (item->identifier == 0)
		;
	else
		ft_putstr_fd("Unknown item->identifier\n", 2);
}

void	ft_export(char **args, t_env_list **env_list)
{
	t_env_item	*item;

	g_errno = 0;
	if (!*args)
		ft_env_list_print_with_declare(*env_list);
	while (*args)
	{
		item = get_env_item_from_envp_string(*args);
		if (!item)
			break ;
		if (item->identifier == -1 || ft_strlen(item->key) == 0)
			identifier_error(*args);
		else if (ft_env_key_exists(*env_list, item->key))
			key_exists_case(env_list, item);
		else
		{
			if (!create_new_env_arg(item->key, item->identifier,
					item->value, env_list))
				break ;
		}
		args++;
		ft_env_item_free(item);
	}
}
