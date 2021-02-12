/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 12:24:29 by dmilan            #+#    #+#             */
/*   Updated: 2021/02/12 09:23:58 by dmilan           ###   ########.fr       */
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

t_env_item	*get_env_item_from_envp_string(const char *envp_string)
{
	int			i;
	t_env_item	*item;

	if (!(item = malloc(sizeof(t_env_item))))
		return (NULL);
	i = 0;
	item->key = NULL;
	item->value = NULL;
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
	char		*key;
	char		*value;
	
	env_list = NULL;
	while(*envp)
	{
		env_item = get_env_item_from_envp_string(*envp);
		ft_env_list_add_back(&env_list, ft_env_list_new(env_item));
		envp++;
	}
	return (env_list);
}

void	ft_env_list_print(t_env_list *env_list)
{
	while (env_list != NULL)
	{
		ft_putstr_fd(env_list->item->key, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(env_list->item->value, 1);
		ft_putstr_fd("\n", 1);
		env_list = env_list->next;
	}
}

int		main(int argc, char **argv, char **envp)
{
	t_vars	vars;
	
	vars.env_list = convert_envp_to_list(envp);
	// ft_env(envp);
	// ft_putendl();
	// ft_putendl();
	// ft_putendl();
	ft_env_list_print(vars.env_list);
	ft_env_list_clear(&vars.env_list);
	return (0);
}