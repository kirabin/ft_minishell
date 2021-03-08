/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 12:24:29 by dmilan            #+#    #+#             */
/*   Updated: 2021/03/08 19:23:16 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int errno;

void	handle_signal(int signal_code)
{
	ft_putendl(NULL);
	ft_putstr_fd("sigal caught: ", 1);
	ft_puti_fd(signal_code, 1);
	ft_putendl(NULL);
	exit(0); // not proper way to exit
}

int		main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	if (argc && argv)
		;
	vars.env_list = convert_envp_to_list(envp);
	signal(SIGINT, handle_signal);
	while (1)
	{
		ft_putstr_fd("minishell> ", 1);
		get_next_line(0, &vars.raw_input);
		parse_row_string(&vars);
		free(vars.raw_input);
	}
	ft_env_list_clear(&vars.env_list);
	return (0);
}
