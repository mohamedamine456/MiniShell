#include "terminal.h"

void	print_termios(t_termios term);

char	*read_words()
{
	t_termios	term;
	t_termios	orig;
	char		*cmd_line;

	if (!get_termios(&term))
		print_termios(term);
	orig = term;
	//term.c_lflag &= ~ISIG;
	//term.c_lflag &= ~FLUSHO;
	if (!set_termios(&term, TCSAFLUSH))
		print_termios(term);
	write(1, "Minishell $> ", 13);
	cmd_line = just_read();
	write(1, cmd_line, ft_strlen(cmd_line));
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

	buff = read_words();
	return (0);
}
