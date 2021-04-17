<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <msamual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 12:24:29 by dmilan            #+#    #+#             */
/*   Updated: 2021/04/17 18:10:12 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

=======
>>>>>>> refs/remotes/origin/master
#include "minishell.h"

void	ft_putprompt(t_vars *vars)
{
	int		x;
	char	*str;

	str = getenv("PWD");
	x = ft_atoi(ft_env_list_get_value(vars->env_list, "SHLVL"));
	if (x == 2)
		ft_putstr("\033[35m");
	else if (x == 3)
		ft_putstr("\033[34m");
	else if (x == 4)
		ft_putstr("\033[32m");
	else if (x == 5)
		ft_putstr("\033[33m");
	else if (x > 5)
		ft_putstr("\033[31m");
	ft_putstr(str);
	ft_putstr(" \033[31m>>>\033[0m ");
}

void	increment_shell_level(t_env_list *lst)
{
	char	*tmp;

	while (lst)
	{
		if (!ft_strcmp(lst->item->key, "SHLVL"))
		{
			tmp = ft_itoa(ft_atoi(lst->item->value) + 1);
			free(lst->item->value);
			lst->item->value = tmp;
			return ;
		}
		lst = lst->next;
	}
}
// autoclosingbrackets

void	init_vars(char **envp, t_vars *vars)
{
	int		fd[2];

	vars->env_list = ft_envp_to_env_list(envp);
	increment_shell_level(vars->env_list);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	init_history(vars);
	pipe(fd);
	vars->stdin_copy = dup2(STD_IN, fd[0]);
	vars->stdout_copy = dup2(STD_OUT, fd[1]);
	vars->term_name = "xterm-256color";
	if (tcgetattr(0, &vars->term) || tcgetattr(0, &vars->term_orig_attr))
		puterror("Error: tcgetattr\n", 1);
	tgetent(0, vars->term_name);
	vars->cursor_pos = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	if (argc && argv)
		;
	init_vars(envp, &vars);
	while (1)
	{
		vars.term.c_lflag &= ~(ECHO);
		vars.term.c_lflag &= ~(ICANON);
		tcsetattr(0, TCSANOW, &vars.term);
		ft_putprompt(&vars);
		tputs(save_cursor, 1, ft_putint);
		read_input(&vars);
	}
	write_history(&vars);
	ft_env_list_clear(&vars.env_list);
	close(vars.stdin_copy);
	close(vars.stdout_copy);
	return (0);
}
