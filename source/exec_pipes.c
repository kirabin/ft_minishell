#include "minishell.h"

void	manage_out_pipe(t_command *command, t_vars *vars)
{
	if (command->pipe_right)
	{
		close(STD_OUT);
		dup2(vars->fd[1], STD_OUT);
	}
	else if (command->pipe_left)
	{
		close(STD_OUT);
		dup2(vars->stdout_copy, STD_OUT);
	}
}

void	manage_in_pipe(t_command *command, t_vars *vars)
{
	if (command->pipe_right)
	{
		close(STD_IN);
		dup2(vars->fd[0], STD_IN);
		close(vars->fd[0]);
		close(vars->fd[1]);
	}
	else if (command->pipe_left)
	{
		close(STD_IN);
		dup2(vars->stdin_copy, STD_IN);
	}
}
