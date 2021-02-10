/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 12:24:29 by dmilan            #+#    #+#             */
/*   Updated: 2021/02/10 10:42:10 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int errno;

void	execute_command(char *command, char **argv, char **envp)
{
	char	**paths;
	int		ret;
	
	argv[0] = ft_strdup(command);
	command = ft_strjoinfreerev("/", command);
	paths = get_env_path_value(envp);
	ret = -1;
	while (*paths)
	{
		*paths = ft_strjoinfree(*paths, command);
		if (ret == -1)
			ret = execve(*paths, argv, envp);  // turn to ft_execve which uses fork 
		free(*paths);
		paths++;
	}
	free(argv[0]);
	free(command);
}

int		main(int argc, char **argv, char **envp)
{
	execute_command(ft_strdup("ls"), argv, envp);


	return (0);
}