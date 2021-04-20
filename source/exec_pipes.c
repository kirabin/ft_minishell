#include "minishell.h"

void	manage_out_pipe(t_command *command, t_vars *vars)
{
	if (command->pipe_right)
	{
		if (command->fd_out != -1)
			write(vars->fd[1], "\0", 1);
		else
		{
			close(STD_OUT);
			dup2(vars->fd[1], STD_OUT);
		}
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

void	open_pipes(t_vars *vars, t_command *command)
{
	if (command->pipe_right)
	{
		if (pipe(vars->fd) == -1)
		{
			g_errno = errno;
			ft_putstr_fd("Pipe, failed, initializing undefined behavior", 2);
		}
	}
}
