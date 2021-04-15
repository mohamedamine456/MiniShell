#include "terminal.h"

void	print_termios(t_termios term);

char	*read_words()
{
	t_termios	orig;
	char		*cmd_line;

	write(1, "Minishell $> ", 13);
	if (!format_terminal(&orig))
	{
		cmd_line = just_read();
		write(1, cmd_line, ft_strlen(cmd_line));
	}
	return (cmd_line);
}

void	print_termios(t_termios term)
{
	printf("\nc_iflag: %ld, c_oflag: %ld, c_cflag: %ld, c_lflag: %ld\n",
			term.c_iflag, term.c_oflag, term.c_cflag, term.c_lflag);
	printf("c_cc: %s, c_ispeed: %ld, c_ospeed: %ld\n",
			term.c_cc, term.c_ispeed, term.c_ospeed);
}

int main(int argc, char **argv, char **envp)
{
	char *buff;
	//t_flags fl;

	//fl = (t_flags){0, 0, 0};
	//if (compare_flags(fl, (t_flags){0, 1, 0}))
	//	write(1, "equals\n", 7);
	//else
	//	write(1, "not\n", 4);
	
	buff = read_words();
	return (0);
}
