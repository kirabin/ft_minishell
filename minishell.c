/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 12:24:29 by dmilan            #+#    #+#             */
/*   Updated: 2021/03/26 11:42:06 by msamual          ###   ########.fr       */
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

void	puterror(int exit_code, char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(exit_code);
}

int		main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	if (argc && argv)
		;
	vars.env_list = convert_envp_to_list(envp);
	signal(SIGINT, handle_signal);
	init_history(&vars);
	vars.term_name = getenv("TERM");
	if (tcgetattr(0, &vars.term) || tcgetattr(0, &vars.term_orig_attr))
		puterror(1, "Error: tcgetattr\n");
	vars.term.c_lflag &= ~(ECHO);
	vars.term.c_lflag &= ~(ICANON);
	if (tcsetattr(0, TCSANOW, &vars.term))
		puterror(1, "Error: tcsetattr\n");
	while (1)
	{
		ft_putstr(PROMPT);
		read_input(&vars);
	}
	ft_env_list_clear(&vars.env_list);
	return (0);
}
