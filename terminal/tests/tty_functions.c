# include <termios.h>
# include <unistd.h>


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
