/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_list_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 09:32:02 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/07 14:50:30 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env_list_len(t_env_list *env_list)
{
	int		len;

	len = 0;
	if (env_list == NULL)
		return (0);
	while (env_list)
	{
		len++;
		env_list = env_list->next;
	}
	return (len);
}
