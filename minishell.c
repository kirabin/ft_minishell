#include "minishell.h"

void	ft_putprompt(void)
{
	int		x;
	char	*str;

	str = "minishell";
	x = 2;
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

void	init_vars(char **envp, t_vars *vars)
{
	vars->env_list = ft_envp_to_env_list(envp);
	increment_shell_level(vars->env_list);
	signal(SIGINT, handle_signals);
	signal(SIGQUIT, handle_signals);
	init_history(vars);
	vars->stdin_copy = dup(STD_IN);
	vars->stdout_copy = dup(STD_OUT);
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
	g_errno = 0;
	init_vars(envp, &vars);
	while (1)
	{
		vars.term.c_lflag &= ~(ECHO);
		vars.term.c_lflag &= ~(ICANON);
		vars.term.c_lflag &= ~(ISIG);
		tcsetattr(0, TCSANOW, &vars.term);
		ft_putprompt();
		tputs(save_cursor, 1, ft_putint);
		read_input(&vars);
	}
	write_history(&vars);
	ft_env_list_clear(&vars.env_list);
	close(vars.stdin_copy);
	close(vars.stdout_copy);
	return (0);
}
