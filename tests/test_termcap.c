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

	//cl_str = tgetstr("cl", 0);
	mv_one = tgetstr("le", 0);
	ce_str = tgetstr("ce", 0);
	del_char = tgetstr("dc", 0);
	del_line = tgetstr("dl", 0);
	cm_str = tgetstr("cm", 0);
	auto_wrap = tgetflag("am");
	nb_col = tgetnum("li");
	nb_rows = tgetnum("co");

	write(1, "Minishell $> hello world", 24);
	write(0, mv_one, ft_strlen(mv_one));
	write(0, mv_one, ft_strlen(mv_one));
	write(0, mv_one, ft_strlen(mv_one));
	
	write(0, ce_str, ft_strlen(ce_str));	
	//write(1, cl_str, ft_strlen(cl_str));
	write(1, "\n", 1);
	//write(1, del_line, ft_strlen(del_line));
	//write(1, "\n", 1);
	//write(1, cm_str, ft_strlen(cm_str));
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
