/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 12:24:29 by dmilan            #+#    #+#             */
/*   Updated: 2021/02/07 15:40:31 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int errno;

int		main(int argc, char **argv, char **envp)
{
	char *temp;
	ft_env(envp);
	ft_putc_fd('\n', 1);

	temp = get_env_value(envp, "LOGNAME");
	ft_putstr_fd(temp, 1);
	
	return (0);
}