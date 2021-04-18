#include "minishell.h"

void	manage_redirections(t_command *command)
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
