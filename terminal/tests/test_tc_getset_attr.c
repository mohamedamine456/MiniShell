#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
# include "../../libft/libft.h"
#define TRUE 1

typedef struct termios t_termios;
void	print_termios(t_termios term);
char	*read_word();


int main(int argc, char **args, char **envp)
{
	t_termios	tp, save;
	char		*buff;

	if (tcgetattr(0, &tp) == -1)
	{
		write(1, "tcgetattr failed", 16);
		return (1);
	}
	print_termios(tp);
	save = tp;
	tp.c_lflag &= ~ECHO;
	if (tcsetattr(0, TCSAFLUSH, &tp))
	{
		write(1, "tcsetattr failed", 16);
		return (1);
	}
	write(1, "Write a word:", 13);
	buff = read_word();
	write(1, "\nread: ", 7);
	write(1, buff, ft_strlen(buff));
	free(buff);
	print_termios(tp);
	return (0);	
}

void	print_termios(t_termios term)
{
	printf("\nc_iflag: %ld, c_oflag: %ld, c_cflag: %ld, c_lflag: %ld\n",
			term.c_iflag, term.c_oflag, term.c_cflag, term.c_lflag);
	printf("c_cc: %s, c_ispeed: %ld, c_ospeed: %ld\n",
			term.c_cc, term.c_ispeed, term.c_ospeed);
}

char	*read_word()
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
			break;
	}
	free(tmp);
	return (buff);
}
