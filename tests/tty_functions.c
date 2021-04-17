# include <termios.h>
# include <unistd.h>
# include <signal.h>
# include <ctype.h>
# include <errno.h>


int		tty_set_cbreak(int fd, struct termios *prev_termios)
{
	struct termios t;

	if (tgetattr(fd, &t) == -1)
		return (-1);
	if (prev_termios != NULL)
		*prev_termios = t;
	t.c_lflag &= ~(ICANON | ECHO);	//noncanonical node, disable echoing
	t.c_lflag |= ISIG;				// enable signals
	
	t.c_iflag &= ~ICRNL;			//map CR to NL

	t.c_cc[VMIN] = 1;				// character-at-a-time input
	t.c_cc[VTIME] = 0;				// with blocking

	if (tsetattr(fd, TCSAFLUSH, &t) == -1)
		return (-1);
	return (0);
}

int		tty_set_raw(int fd, struct termios *prev_termios)
{
	struct termios t;

	if (tgetattr(fd, &t) == -1)
		return (-1);
	if (prev_termios != NULL)
		*prev_termios = t;
	t.c_lflag &= ~(ICANON | ISIG | IEXTEN | ECHO);
	//noncanonical mode, disable signals, extended input processing, and echoing
	t.c_iflag &= (BRKINT | ICRNL | IGNBRK | IGNCR | INLCR | INPCK | ISTRIP | IXON | PARMRK);
	// disable special hangling of Cr, NL, and BREAK. No*th-bit sstripping or parity error handling
	// disable START/STOP output flow control.

	t.c_oflag &= ~OPOST;		//Disable all output processing
	t.c_cc[VMIN] = 1;			//character-at-a-time input
	t.c_cc[VTIME] = 0;			//with blocking

	if (tsetattr(fd, TCSAFLUSH, &t) == -1)
		return (-1);
	return (0);
}

static struct termios user_termios;

void	handler(int sig)
{
	if (tcsetattr(0, TCSAFLUSH, &user_termios) == -1)
	{
		write(1, "tcsetattr error\n", 16);
		exit(1);
	}
	exit(0);
}

void	tstp_handler(int sig)
{
	struct	termios our_termios;

	sigset_t tstp_mask, prev_mask;
	struct sigaction sa;
	int	saved_errno;

	saved_errno = errno;
	if (tgetattr(0, &our_termios) == -1)
	{
		write(1, "tcgetattr error\n", 16);
		exit(1);
	}
	if (tcsetattr(0, TCAFLUSH, &user_termios) == -1)
	{
		write(1, "tcsetattr error\n", 16);
		exit(1);
	}
	if (signal(SIGTSTP, SIG_DFL) == SIG_ERR)
	{
		write(1, "signal error\n", 12);
		exit(1);
	}
}
