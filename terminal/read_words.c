#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <termios.h>
#define TRUE 1
#include "../libft/libft.h"

typedef struct termios	t_termios;

char	*just_read();
int		set_termios(t_termios *term, int flag);
int		get_termios(t_termios *term);
void	print_termios(t_termios term);

char	*read_words()
{
	t_termios	term;
	t_termios	orig;
	char		*cmd_line;

	if (!get_termios(&term))
		print_termios(term);
	orig = term;
	term.c_lflag &= ~ISIG;
	term.c_lflag &= ~FLUSHO;
	if (!set_termios(&term, TCSAFLUSH))
		print_termios(term);
	write(1, "Minishell $> ", 13);
	cmd_line = just_read();
	write(1, cmd_line, ft_strlen(cmd_line));
	return (cmd_line);
}

int		get_termios(t_termios *term)
{
	if (tcgetattr(0, term) == -1)
		return (-1);
	else
		return (0);
}

int		set_termios(t_termios *term, int flag)
{
	if (tcsetattr(0, flag, term) == -1)
		return (-1);
	else
		return (0);
}

void	print_termios(t_termios term)
{
	printf("\nc_iflag: %ld, c_oflag: %ld, c_cflag: %ld, c_lflag: %ld\n",
			term.c_iflag, term.c_oflag, term.c_cflag, term.c_lflag);
	printf("c_cc: %s, c_ispeed: %ld, c_ospeed: %ld\n",
			term.c_cc, term.c_ispeed, term.c_ospeed);
}

char	*just_read()
{
	char	*buff;
	char	*tmp;

	buff = NULL;
	tmp = malloc(2);
	while (TRUE)
	{
		if (read(0, tmp, 1) > 0)
		{
			tmp[1] = '\0';
			if (buff == NULL)
				buff = ft_strdup("");
			buff = ft_strjoin(buff, tmp);
			if (tmp[0] == '\n')
				break ;
		}
		else
			break ;
	}
	free(tmp);
	return (buff);
}

int main(int argc, char **argv, char **envp)
{
	char *buff;

	buff = read_words();
	return (0);
}
