/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:43:10 by eel-orch          #+#    #+#             */
/*   Updated: 2021/04/18 17:00:56 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft/libft.h"
#include <string.h>

void	sort_strings(char **tab)
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
		tmp = tab[index];
		while (j >= 0 && (ft_strcmp(tab[j], tab[index]) > 0))
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = tmp;
		index++;
	}
	int i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

//int main()
//{
//	char **tab = ft_split("kk Aaaa Caba AAAAAA", 32);
//	sort_strings(tab);
//	int i = 0;
//	while (tab[i])
//	{
//		printf("%s\n", tab[i]);
//		free(tab[i]);
//		i++;
//	}
//	free(tab);
//	return (0);
//}

