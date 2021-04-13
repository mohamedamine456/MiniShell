
#include "../libft/libft.h"

void	sort_string(char **tab)
{
    char    *tmp;
    int	    index;
    int	    j;
    int	    tab_len;

    index = 1;
    tab_len = ft_strlen_tab(tab);
    while (index < tab_len)
    {
	j = index - 1;
	while (j >= 0 && (ft_strcmp(tab[j], tab[index]) > 0))
	{
	    tab[j + 1] = tab[j];
	    j--;
	}
	tab[j + 1] = tab[index];
	index++;
    }
}

int main()
{
    char **tab = ft_split("okkkkk aaaaa baba", 32);
    sort_string(tab);
    int i = 0;
    while (tab[i])
    {
	printf("%s\n", tab[i]);
	i++;
    }
    return (0);
}

