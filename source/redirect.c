/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:43:12 by msamual           #+#    #+#             */
/*   Updated: 2021/04/16 18:22:39 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect(t_raw_command *com, char *file_name)
{
	if (com->redirect == 3)
	{
		if (com->redirect_out != -1)
			close(com->redirect_out);
		com->redirect_out = open(file_name, O_APPEND | O_CREAT, S_IRWXU);
		if (com->redirect_out == -1)
			return (puterror(NULL, errno));
	}
	else if (com->redirect == 2)
	{
		if (com->redirect_out != -1)
			close(com->redirect_out);
		com->redirect_out = open(file_name, O_WRONLY | O_CREAT, S_IRWXU);
		if (com->redirect_out == -1)
			return (puterror(NULL, errno));
	}
	else if (com->redirect == 1)
	{
		if (com->redirect_in != -1)
			close(com->redirect_in);
		com->redirect_in = open(file_name, O_RDONLY, S_IRWXU);
		if (com->redirect_in == -1)
			return (puterror(NULL, errno));
	}
	return (0);
}
