#include "../libft/libft.h"
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

void	get_data()
{
	int		nb_col;
	int		nb_rows;
	int		auto_wrap;
	char	*cl_str;
	char	*cm_str;

	cl_str = tgetstr("cl", 0);
	cm_str = tgetstr("cm", 0);
	auto_wrap = tgetflag("am");
	nb_col = tgetnum("li");
	nb_rows = tgetnum("co");
	printf("{%s} {%s} {%d}\n", cl_str, cm_str, auto_wrap);
	printf("%d, %d\n", nb_col, nb_rows);
}

void	init_terminal_data()
{
	char	*termtype;
	char	*term_buffer;
	int		success;

	term_buffer = NULL;
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
	get_data();
	return (0);
}
