/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:08:07 by msamual           #+#    #+#             */
/*   Updated: 2021/04/08 13:45:57 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_list_size(t_env_list *lst)
{
	int		res;

	res = 0;
	while (lst)
	{
		res++;
		lst = lst->next;
	}
	return (res);
}

char	**list_to_array(t_env_list *lst)
{
	char	**res;
	int		i;

	i = 0;
	res = ft_calloc(ft_list_size(lst) + 1, sizeof(char *));
	while (lst)
	{
		res[i] = ft_calloc((ft_strlen(lst->item->key) + ft_strlen(lst->item->value) + 2), sizeof(char));
		ft_strlcat(res[i], lst->item->key, ft_strlen(lst->item->key));
		ft_strlcat(res[i], "=", 1);
		ft_strlcat(res[i], lst->item->value, ft_strlen(lst->item->value));
		lst = lst->next;
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	execute(t_vars *vars, t_command *com)
{
	// char	**envp;

	(void)vars;
	// envp = list_to_array(vars->env_list);
	print_tab(com);
	// execve("/bin/pwd", com->com, envp);
	//execute_command_struct(vars, com);
	// free(envp);
}