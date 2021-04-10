#include <unistd.h>
#include <stdio.h>
#include <termios.h>

typedef struct termios t_termios;

int main(int argc, char **args, char **envp)
{
	t_termios tp, save;
	char buff[14];

	if (tcgetattr(0, &tp) == -1)
	{
		write(1, "tcgetattr failed", 16);
		return (1);
	}
	printf("c_iflag: %ld, c_oflag: %ld, c_cflag: %ld, c_lflag: %ld\n",
			tp.c_iflag, tp.c_oflag, tp.c_cflag, tp.c_lflag);
	printf("c_cc: %s, c_ispeed: %ld, c_ospeed: %ld\n",
			tp.c_cc, tp.c_ispeed, tp.c_ospeed);
	save = tp;
	tp.c_lflag &= ~ECHO;
	if (tcsetattr(0, TCSAFLUSH, &tp))
	{
		write(1, "tcsetattr failed", 16);
		return (1);
	}
	write(1, "Write a word:", 13);
	read(0, buff, 13);
	write(1, "\nread: ", 7);
	write(1, buff, 13);
	printf("\nc_iflag: %ld, c_oflag: %ld, c_cflag: %ld, c_lflag: %ld\n",
			tp.c_iflag, tp.c_oflag, tp.c_cflag, tp.c_lflag);
	printf("c_cc: %s, c_ispeed: %ld, c_ospeed: %ld\n",
			tp.c_cc, tp.c_ispeed, tp.c_ospeed);
	return (0);	
}
