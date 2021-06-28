#include "libft.h"

char	**ft_strjoin_tables(char **str1, char **str2)
{
	char	**tab;
	int		len;
	int		len_s1;
	int		len_s2;
	int		index;

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

//int main()
//{
//    char **tab = ft_split("okkk test allah allah", 32);
//    char *str = ft_strdup("akbar");
//    char **tab2 = ft_split("wa7ed jouj", 32);
//    char **new_tab = ft_strjoin_tables(tab, tab2);
//    int i = 0;
//    while (new_tab[i] != NULL)
//    {
//	printf("%s\n", new_tab[i]);
//	i++;
//    }
//    char **testo = ft_split("ramadan", 32);
//    i = 0;
//    while (testo[i] != NULL)
//    {
//	printf("%s\n", testo[i]);
//	i++;
//    }
//}
