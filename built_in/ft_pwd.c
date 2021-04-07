/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 09:35:09 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/07 14:55:03 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**   Print current working directory
**    - No options
**    - Ignores arguments
*/

int	ft_pwd(void)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	if (!buf)
	{
		ft_putstr_fd(strerror(errno), 2);
		return (0);
	}
	ft_putstr_fd(buf, 1);
	ft_putc_fd('\n', 1);
	free(buf);
	return (1);
}
