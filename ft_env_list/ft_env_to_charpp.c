/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_to_charpp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 09:21:16 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/13 08:24:16 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_env_item_to_charp(t_env_item *item)
{
	char	*line;
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(item->key) + ft_strlen(item->value) + 1;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (++i < (int)ft_strlen(item->key))
		line[i] = item->key[i];
	line[i] = '=';
	while (++i < len)
		line[i] = item->value[i - 1 - ft_strlen(item->key)];
	line[len] = '\0';
	return (line);
}

char	**ft_env_to_charpp(t_env_list *list)
{
	char	**envp;
	int		len;
	int		i;

	i = 0;
	len = ft_env_list_len(list);
	envp = malloc(sizeof(char *) * (len + 1));
	if (!envp)
		return (NULL);
	while (list)
	{
		envp[i] = ft_env_item_to_charp(list->item);
		if (!envp[i])
		{
			while (i >= 0)
				free(envp[i--]);
			return (NULL);
		}
		i++;
		list = list->next;
	}
	envp[len] = NULL;
	return (envp);
}
