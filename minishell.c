/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 12:24:29 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/15 16:34:45 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **envp)
{
	t_vars	vars;
	int		fd[2];

	if (argc && argv)
		;
	vars.env_list = ft_envp_to_env_list(envp);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	// ft_env_list_print(vars.env_list);
	init_history(&vars);
	pipe(fd);
	vars.stdin_copy = dup2(STD_IN, fd[0]);
	vars.stdout_copy = dup2(STD_OUT, fd[1]);
	vars.term_name = "xterm-256color";
	if (tcgetattr(0, &vars.term) || tcgetattr(0, &vars.term_orig_attr))
		puterror("Error: tcgetattr\n", 1);
	vars.term.c_lflag &= ~(ECHO);
	vars.term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &vars.term);
	tgetent(0, vars.term_name);
	while (1)
	{
		ft_putstr(PROMPT);
		tputs(save_cursor, 1, ft_putint);
		read_input(&vars);
	}
	write_history(&vars);
	ft_env_list_clear(&vars.env_list);
	close(vars.stdin_copy);
	close(vars.stdout_copy);
	return (0);
}