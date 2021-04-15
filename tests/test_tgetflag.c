#include "../../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include <term.h>

int main(int argc, char **argv)
{
	int id_tgf;

	id_tgf = tgetflag(argv[1]);
	printf("%d\n", id_tgf);
	return (0);
}
