#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include <termios.h>
#include <readline/readline.h>
#include <readline/history.h>

int main()
{
	char *line;

	while (1)
	{
		line = readline("bash %> ");
		if (!strcmp(line, "exit"))
			break ;
		if (line != NULL && strcmp(line, ""))
		{
			write(STDOUT_FILENO, "Line Eneterd: ", 14);
			write(STDOUT_FILENO, line, strlen(line));
		}
	}
}
