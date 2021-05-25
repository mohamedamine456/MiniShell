#include "libft.h"

int ft_strlen_tab(char **tab)
{
    int len;

    len = 0;
    if (tab == NULL)
      return (0);
    while (tab[len] != NULL)
		  len++;
    return (len);
}
