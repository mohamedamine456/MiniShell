#include "libft.h"

char **ft_strjoin_tables(const char **str1, const char **str2)
{
    char    **tab;
    int	    len;
    int	    len_s1;
    int	    len_s2;
    int	    index;

    len_s1 = ft_strlen_tab((char **)str1);
    len_s2 = ft_strlen_tab((char **)str2);
    len = len_s1 + len_s2;
    tab = (char **)malloc(sizeof(char *) * (len + 1));
    index = 0;
    while (index < len_s1)
    {
	tab[index] = ft_strdup(str1[index]);
	index++;
    }
    len = 0;
    while (index < len_s1 + len_s2)
    {
	tab[index] = ft_strdup(str2[len]);
	index++;
	len++;
    }
    tab[index] = NULL;
    return (tab);
}
