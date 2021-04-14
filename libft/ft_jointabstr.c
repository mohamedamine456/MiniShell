
#include "libft.h"

char **ft_jointabstr(char **tab, char *str)
{
    char    **tmp_tab;
    char    **new_tab;
    int	    i;

    tmp_tab = (char **)malloc(sizeof(char *) * 2);
    tmp_tab[0] = ft_strdup(str);
    tmp_tab[1] = NULL;
    new_tab = ft_strjoin_tables(tab, tmp_tab);
    free(tmp_tab[0]);
    free(tmp_tab);
    return (new_tab);
}
