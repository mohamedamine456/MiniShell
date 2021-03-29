#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	int i;

	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	if (src < dest)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i--;
		}
	}
	else
	{
		while (i < (int)n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}