/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 12:24:29 by dmilan            #+#    #+#             */
/*   Updated: 2021/02/14 10:40:06 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int errno;

// void	execute_command(char *command, char **argv, char **envp)
// {
// 	char	**paths;
// 	int		ret;
	
// 	argv[0] = ft_strdup(command);
// 	command = ft_strjoinfreerev("/", command);
// 	paths = get_env_path_value(envp);
// 	ret = -1;
// 	while (*paths)
// 	{
// 		*paths = ft_strjoinfree(*paths, command);
// 		if (ret == -1)
// 			ret = execve(*paths, argv, envp);  // turn to ft_execve which uses fork 
// 		free(*paths);
// 		paths++;
// 	}
// 	free(argv[0]);
// 	free(command);
// }

t_env_item	*get_env_item_from_envp_string(const char *envp_string)
{
	int			i;
	t_env_item	*item;

	i = 0;
	item = ft_env_item_new(NULL, NULL);
	while (envp_string[i] != '=')
		i++;
	item->key = ft_strndup(envp_string, i);
	envp_string += i + 1;
	item->value = ft_strdup(envp_string);
	return (item);
}

t_env_list	*convert_envp_to_list(char **envp)
{
	t_env_list	*env_list;
	t_env_item	*env_item;

	env_list = NULL;
	while(*envp)
	{
		env_item = get_env_item_from_envp_string(*envp);
		ft_env_list_add_back(&env_list, ft_env_list_new(env_item));
		envp++;
	}
	return (env_list);
}

void	handle_signal(int signal_code)
{
	ft_putendl();
	ft_putstr_fd("sigal caught", 1);
	ft_putendl();
	exit(0);
}

int		main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	vars.env_list = convert_envp_to_list(envp);
	signal(SIGINT, handle_signal);
	while (1)
	{
		ft_putstr_fd("minishell> ", 1);
		get_next_line(0, &vars.raw_input);
		ft_putstr_fd(vars.raw_input, 1);
		ft_putendl();
		free(vars.raw_input);
	}
	ft_env_list_clear(&vars.env_list);
	return (0);
}
