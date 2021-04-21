/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:43:12 by msamual           #+#    #+#             */
/*   Updated: 2021/04/21 12:03:57 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect(t_raw_command *com, char *f)
{
	if (com->redirect == 3)
	{
		if (com->redirect_out != -1)
			close(com->redirect_out);
		com->redirect_out = open(f, O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);
		if (com->redirect_out == -1)
			return (puterror_three(f, ": ", strerror(errno), errno));
	}
	else if (com->redirect == 2)
	{
		if (com->redirect_out != -1)
			close(com->redirect_out);
		com->redirect_out = open(f, O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU);
		if (com->redirect_out == -1)
			return (puterror_three(f, ": ", strerror(errno), errno));
	}
	else if (com->redirect == 1)
	{
		if (com->redirect_in != -1)
			close(com->redirect_in);
		com->redirect_in = open(f, O_RDONLY, S_IRWXU);
		if (com->redirect_in == -1)
			return (puterror_three(f, ": ", strerror(errno), errno));
	}
	return (0);
}
