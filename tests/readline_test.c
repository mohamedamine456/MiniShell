#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include <termios.h>
#include <readline/readline.h>
#include <readline/history.h>

int init_terminal_data(void)
{
    char    *termtype;
    char    *term_buffer;
    int     success;

    term_buffer = NULL;
    termtype = getenv("TERM");
    if (termtype == NULL)
        return (-1);
    success = tgetent(termtype, term_buffer);
    if (success < 0)
        return (-1);
    return (0);
}

int get_termios(struct termios *term)
{
    if (tcgetattr(0, term) == -1)
        return (-1);
    else
        return (0);
}

int set_termios(struct termios *term, int flag)
{
    if (tcsetattr(0, flag, term) == -1)
        return (-1);
    else
        return (0);
}

int format_terminal(struct termios *orig)
{
    struct termios  term;

    if (init_terminal_data() == -1)
        return (-1);
    if (!get_termios(&term))
    {
        *orig = term;
        term.c_lflag &= ~ (ICANON | ISIG | ECHO);
        if (!set_termios(&term, TCSAFLUSH))
            return (0);
        return (-1);
    }
    return (-1);
}

int main()
{
	char *line;
	struct termios orig;

	init_terminal_data();
	format_terminal(&orig);
	line = readline("bash %> ");
	write(STDOUT_FILENO, "Line Eneterd: ", 14);
	if (line != NULL)
		write(STDOUT_FILENO, line, strlen(line));
}
