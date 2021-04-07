/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 09:47:21 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/06 15:13:24 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**   Print environment variables
**    - No options
**    - No arguments
*/

int		ft_env(t_env_list *env_list)
{
	ft_env_list_print(env_list);
	return (1);
}