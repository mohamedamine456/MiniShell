#include "libft.h"

/**
 * This function to simply add a string to table of strings
*/

char		**ft_resize_tab(char **old, char *chaine)
{
	char **new;
	int i;
	int len;

	i = 0;
	if (old == NULL)
		len = 0;
	else
		len = ft_size_args(old);
	new = (char **)malloc(sizeof(char *) * (len + 2));
	while (i < len)
	{
		new[i] = ft_strdup(old[i]);
		i++;
	}
	new[i] = ft_strdup(chaine);
	new[i + 1] = NULL;
	ft_free_args(old);
	free(chaine);
	return (new);
}