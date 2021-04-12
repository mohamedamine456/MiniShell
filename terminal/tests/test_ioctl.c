#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include "../../libft/libft.h"

typedef struct		s_winsize
{
	int	w_row;
	int	w_col;
	int	w_xpixel;
	int	w_ypixel;
}					t_winsize;

int main()
{
	t_winsize	winsize;
	char		number[20];

	if (ioctl(0, TIOCGWINSZ, &winsize) == -1)
		write(1, "can't get winsize", 17);
	else
	{
		write(1, "windows rows: ", 14);
		ft_putnbr(winsize.w_row);
		write(1, "\n", 1);	
		write(1, "windows columns: ", 18);
		ft_putnbr(winsize.w_col);
		write(1, "\n", 1);
		
		write(1, "windows xpixels: ", 17);
		ft_putnbr(winsize.w_xpixel);
		write(1, "\n", 1);

		write(1, "windows ypixels: ", 17);
		ft_putnbr(winsize.w_ypixel);
		write(1, "\n", 1);

	}
}
