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
	char	*del_line;
	char	*ce_str;
	char	*tgoto_str;
	char	*del_char;
	char	*mv_one;
	char	*dc;
	char	*dm;
	char	*ed;

	//cl_str = tgetstr("cl", 0);
	mv_one = tgetstr("le", 0);
	ce_str = tgetstr("ce", 0);
	del_char = tgetstr("dc", 0);
	del_line = tgetstr("dl", 0);
	cm_str = tgetstr("cm", 0);
	auto_wrap = tgetflag("am");
	nb_col = tgetnum("li");
	nb_rows = tgetnum("co");
	dc = tgetstr("dc", 0);
	dm = tgetstr("dm", 0);
	ed = tgetstr("ed", 0);

	write(1, "Minishell $> hello world", 24);
	tputs(mv_one, 1, ft_putchar);
	tputs(mv_one, 1, ft_putchar);
	tputs(mv_one, 1, ft_putchar);
	tputs(mv_one, 1, ft_putchar);

	tputs(dm, 1, ft_putchar);

	tputs(ce_str, 1, ft_putchar);
	tputs(mv_one, 1, ft_putchar);
	tputs(dc, 1, ft_putchar);
	tputs(ed, 1, ft_putchar);
	//tputs(cl_str, 1, ft_putchar);
	write(1, "\n", 1);
	//tputs(del_line, 1, ft_putchar);
	//write(1, "\n", 1);
	//tputs(cm_str, 1, ft_putchar);
	//write(1, "\n", 1);
	//printf("{%s} {%s} {%d}\n", cl_str, cm_str, auto_wrap);
	//printf("%d, %d\n", nb_col, nb_rows);
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
