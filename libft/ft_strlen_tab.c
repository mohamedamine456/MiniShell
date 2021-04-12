#include "libft.h"

int ft_strlen_tab(char **tab)
{
    int len;

    len = 0;
    while (tab[len] != NULL)
	len++;
    return (len);
}
