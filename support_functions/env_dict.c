/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:13:46 by dmilan            #+#    #+#             */
/*   Updated: 2021/02/07 15:54:33 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_env_value(char **envp, char *key)
{
	char	*value;
	char	*temp; //rm
	int		len;
	int		i;
	
	i = 0;
	value = NULL;
	if (!envp)
		return (NULL);
	len = ft_strlen(key);
	while (envp[i])
	{
		temp = envp[i]; //rm
		if (ft_strncmp(key, envp[i], len) == 0)
		{
			value = envp[i] + len + 1;
			return (value);      // should I return a copy ?
		}
		i++;
	}
	return (NULL);
}