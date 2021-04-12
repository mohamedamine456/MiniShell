#include "../../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <term.h>

void	fatal(char *err)
{
	if (err != NULL)
		write(1, err, ft_strlen(err));
	exit(1);
}

void	init_terminal_data()
{
	char	*termtype;
	char	*term_buffer;
	int		success;

	term_buffer = malloc(2048);
	termtype = getenv("TERM");
	if (termtype == NULL)
		fatal("Specify a terminal type in the env variables.\n");
	success = tgetent(termtype, term_buffer);
	if (success < 0)
		fatal("Could not access the termcap data base.\n");
	if (success == 0)
		printf("terminal '%s' type is not defined.\n", termtype);
}

int main()
{
	init_terminal_data();
	return (0);
}
