#include "terminal.h"

void	print_termios(t_termios term);

int main(int argc, char **argv, char **envp)
{
	char *buff;	
	buff = read_line();
	return (0);
}

char	*read_line()
{
	t_termios	orig;
	char		*cmd_line;

	if (!format_terminal(&orig))
	{
		write(1, "Minishell $> ", 13);
		cmd_line = just_read();
		write(1, "\n", 1);
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
