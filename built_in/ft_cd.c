/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 09:46:52 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/13 09:15:29 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	SUBJECT
**		- Works only with relative and absolute path
**		- No options
**		- Like in bash
**
**	ARGS
**		- Tries to change directory by passed path
**
**	OPTIONS / FLAGS
**		-[n] Do not output the trailing newline
**
**	EXIT STATUS
**		-[0] Successful completion.
**		-[>0] An error occurred.
*/

/*
**   Change Directory
**    - Absolute or Relative path
**    - No options
*/

void	ft_cd(const char *new_path, t_env_list *list)
{
	if (new_path == NULL)
		new_path = ft_env_list_get_value(list, "HOME");
	if (chdir(new_path) == -1)
	{
		g_errno = errno;
		ft_putstr_fd(strerror(g_errno), 2);
		ft_putstr_fd("\n", 2);
		return ;
	}
	g_errno = 0;
}