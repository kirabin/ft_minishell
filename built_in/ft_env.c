/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 09:47:21 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/11 13:22:13 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	SUBJECT
**		- No options
**		- No arguments
**		- Like in bash
**
**	ARGS
**		- Ignores arguments
**
**	EXIT STATUS
**		-[0] Successful completion.
**		-[>0] An error occurred.
*/

void	ft_env(t_env_list *env_list)
{
	ft_env_list_print(env_list);
	g_errno = 0;
}