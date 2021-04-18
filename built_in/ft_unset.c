/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 09:47:31 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/11 12:09:53 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	SUBJECT
**		- No Options
**		- Like in bash
**
**	ARGS
**		- Tries to unset arguments one by one
**
**	EXIT STATUS
**		-[0] All name operands were successfully unset.
**		-[>0] At least one name could not be unset.
*/

static void	identifier_error(char *str)
{
	ft_putstr_fd("unset: `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	g_errno = 1;
}

void	ft_unset(t_env_list **list, char **keys)
{
	g_errno = 0;
	while (*keys)
	{
		if (!is_name(*keys))
			identifier_error(*keys);
		else if (!ft_env_list_remove(list, *keys))
			;
		keys++;
	}
}
