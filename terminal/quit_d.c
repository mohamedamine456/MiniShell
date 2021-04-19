# include "terminal.h"

void	quit_d(char *line)
{
	free(line);
	write(1, "exit\n", 5);
	exit(0);
}
