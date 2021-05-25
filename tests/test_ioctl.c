#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct		s_winsize
{
	int	w_row;
	int	w_col;
	int	w_xpixel;
	int	w_ypixel;
}					t_winsize;

int main()
{
	unsigned short *a;
	unsigned short *b;
	unsigned short *c;
	unsigned short *d;

	struct ttysize win;

	a = &(win.ts_lines);
	b = &(win.ts_cols);
	char		number[20];

	if (ioctl(0, TIOCGWINSZ, &win) == -1)
		write(1, "can't get winsize", 17);
	else
	{
		write(1, "windows rows: ", 14);
		ft_putnbr(win.ts_lines);
		ft_putnbr(*a);
		write(1, "\n", 1);	
		write(1, "windows columns: ", 18);
		ft_putnbr(win.ts_cols);
		write(1, "\n", 1);
		
		write(1, "windows xpixels: ", 17);
		ft_putnbr(win.ts_xxx);
		write(1, "\n", 1);

		write(1, "windows ypixels: ", 17);
		ft_putnbr(win.ts_yyy);
		write(1, "\n", 1);

	}
}
