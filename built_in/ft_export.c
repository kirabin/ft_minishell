/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 09:47:27 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/11 13:48:33 by dmilan           ###   ########.fr       */
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

void	ft_export(char **args, t_env_list **env_list)
{
	t_env_item	*item;
	t_env_item	*tmp;

	g_errno = 0;
	if (!*args)
		ft_env_list_print_with_declare(*env_list);
	while (*args)
	{
		item = get_env_item_from_envp_string(*args);
		if (item->identifier == -1) //|| (item->value && item->identifier == 0)
			identifier_error(*args);
		else if (ft_env_key_exists(*env_list, item->key))
		{
			if (item->identifier == 1)
				ft_env_list_replace(*env_list, item);
			else if (item->identifier == 2)
			{
				tmp = ft_get_env_item_with_key(*env_list, item->key);
				tmp->value = ft_strjoin_free(tmp->value,
													item->value);
			}
			else if (item->identifier == 0)
				;
			else
				ft_putstr_fd("Unknown item->identifier\n", 2);
		}
		else
		{
			tmp = ft_env_item_new(ft_strdup(item->key), item->identifier, ft_strdup(item->value));
			ft_env_list_add_back(env_list, ft_env_list_new(tmp));
		}
		args++;
		ft_env_item_free(item);
	}
}
