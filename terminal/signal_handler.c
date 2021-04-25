#include "terminal.h"

void	signal_handler(void)
{
	if (signal(SIGINT, ctrl_c_handler) == SIG_ERR)
		exit(1);
	if (signal(SIGQUIT, ctrl_bs_handler) == SIG_ERR)
		exit(1);
}

void	ctrl_c_handler(int sig)
{
	sig = 0;
	//if (!ft_strcmp(hist.command_line, ""))
	write(1, "\nMiniShell $> ", 14);//do  nothing when buffer is not empty
	return ;
}

void	ctrl_bs_handler(int sig)
{
	sig = 0;
	return ;
}
