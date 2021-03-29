# include "libft.h"

/**
 * count the size of table of strings
*/

int		ft_size_args(char **tab)
{
	int		i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i] != NULL)
			i++;
	}
	return (i);
}