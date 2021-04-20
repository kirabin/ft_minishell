#include "minishell.h"

void	open_redirections(t_command *command)
{
	if (command->fd_in != -1)
	{
		close(STD_IN);
		dup2(command->fd_in, STD_IN);
	}
	if (command->fd_out != -1)
	{
		close(STD_OUT);
		dup2(command->fd_out, STD_OUT);
	}
}

void	close_redirections(t_vars *vars, t_command *command)
{
	if (command->fd_in != -1 || command->fd_out != -1)
	{
		dup2(vars->stdout_copy, STD_OUT);
		dup2(vars->stdin_copy, STD_IN);
	}
}
