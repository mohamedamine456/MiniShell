# include "libft.h"

char	**ft_strjoin_args(char **tab, char *str)
{
	int i;

	i = 0;

	if (tab == NULL || str == NULL)
		return (NULL);
	while (tab[i] != NULL)
	{
		tab[i] = ft_strjoin(tab[i],str);
		i++;
	}
	free(str);
	return (tab);
}
