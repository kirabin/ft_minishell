/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:43:12 by msamual           #+#    #+#             */
/*   Updated: 2021/04/14 14:36:56 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		redirect(t_command *com, char *file_name)
{
	if (com->redirect == 3)
	{
		com->redirect_out = open(file_name, O_APPEND);
		if (com->redirect_out == -1)
			return (puterror(NULL, errno));
	}
	else if (com->redirect == 2)
	{
		com->redirect_out = open(file_name, O_RDONLY);
		if (com->redirect_out == -1)
			return (puterror(NULL, errno));
	}
	else if (com->redirect == 1)
	{
		com->redirect_in = open(file_name, O_WRONLY);
		if (com->redirect_in == -1)
			return (puterror(NULL, errno));
	}
	return (0);
}