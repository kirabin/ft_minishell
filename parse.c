/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 11:57:38 by msamual           #+#    #+#             */
/*   Updated: 2021/02/14 12:04:39 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_row_string(t_vars *vars)
{
	char	*str;

	str = vars->raw_input;
	ft_putendl(str);
}