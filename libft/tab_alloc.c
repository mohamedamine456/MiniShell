#include "libft.h"

char **tab_alloc(char **tab)
{
    char    **new_tab;
    int	    tab_len;

    tab_len = ft_strlen_tab(tab);
    new_tab = (char **)malloc(sizeof(char *) * (tab_len + 1));
    return (new_tab);
}
