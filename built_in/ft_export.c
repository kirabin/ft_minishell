/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 09:47:27 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/07 09:21:16 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**   Set environment variable
**    - No options
**    - Args: NAME=VALUE NAME2=VALUE2
**
**   Returns:
**    - 0   - All name operands were successfully exported.
**    - >0  - At least one name could not be exported
*/

//	TODO: export cases
//	[+] export
//	[ ] export a            Adds without identifier if it didn't exist, else ignores it
//	[ ] export a= a=1 a==1
//	[ ] export a= a=1 a=+1  Creates key with empty or set string
//	[ ] export a=2          Rewrites created key
//	[ ] export a+=2         Concatenates string
//	[ ] export c+=2         Creates new and con
//	[ ] export mulpiple_arguments
//	[ ] export export a+abc=1    Should be error
//
//	[+] a=1; export a			Shouldn't handle it by subject, just setting empty value.
//


static void		identifier_error(char *str)
{
	ft_putstr_fd("export: `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

int				ft_export(char **args, t_env_list **env_list)
{
	t_env_item	*item;
	t_env_item	*old_item;

	while (*args)
	{
		item = get_env_item_from_envp_string(*args);
		if (item->identifier == -1)
		{
			identifier_error(*args);
			ft_env_item_free(item);
		}
		else if (item->key)
		{
			if (ft_env_key_exists(*env_list, item->key))
			{
				if (item->identifier == 1)
					ft_env_list_replace(*env_list, item->key, item->value);
				else if (item->identifier == 2)
				{
					old_item = ft_get_env_item_with_key(*env_list, item->key);
					old_item->value = ft_strjoinfree(old_item->value,
														item->value);
				}
				else if (item->identifier == 0)
				{
					;
				}
				else
				{
					ft_putstr_fd("Unknown item->identifier\n", 2);
				}
				ft_env_item_free(item);
			}
			else
			{
				ft_env_list_add_back(env_list, ft_env_list_new(item));
			}
		}
		else
		{
			ft_env_list_print_with_declare(*env_list);
			ft_env_item_free(item);
		}
		args++;
	}
	return (1); // TODO: returns
}