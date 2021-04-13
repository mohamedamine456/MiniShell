#include "libft.h"

char **insert_string(char **tab, char *str, int index)
{
    char    **new_tab;
    int	    tab_len;
    int	    i;
    int	    j;

    tab_len = 0;
    i = 0;
    j = 0;
    while (tab[tab_len] != NULL)
	tab_len++;
    tab_len++;
    new_tab = (char **)malloc(sizeof(char) * (tab_len + 1));
    while (i < tab_len)
    {
	if (i == index)
	    new_tab[i++] = ft_strdup(str);
	else
	    new_tab[i++] = tab[j++];
    }
    new_tab[i] = NULL;
    return (new_tab);
}
