#include "libft.h"

void	ft_putnbr(int n)
{
	long	nbs;
	int		m;
	char	c;

	nbs = n;
	m = 0;
	if (nbs < 0)
	{
		write(1, "-", 1);
		nbs *= -1;
	}
	if (nbs >= 0 && nbs <= 9)
	{
		c = nbs + 48;
		write(1, &c, 1);
	}
	else
	{
		m = nbs % 10;
		nbs /= 10;
		ft_putnbr(nbs);
		c = m + 48;
		write(1, &c, 1);
	}
}