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

#include "built_in.h"

void	sort_strings(char **table)
{
	char    *tmp;
	int	    index;
	int	    j;
	int	    table_len;

	index = 1;
	table_len = ft_strlen_tab(table);
	while (index < table_len)
	{
		j = index - 1;
		tmp = table[index];
		while (j >= 0 && (ft_strcmp(table[j], tmp) >= 0))
		{
			table[j + 1] = table[j];
			j--;
		}
		table[j + 1] = tmp;
		index++;
	}
}

// int main()
// {
// 	char **tab = ft_split("kk Aaaa Caba AAAAA", 32);
// 	sort_strings(tab);
// 	int i = 0;
// 	// while (tab[i])
// 	// {
// 	// 	printf("%s\n", tab[i]);
// 	// 	free(tab[i]);
// 	// 	i++;
// 	// }
// 	free(tab);
// 	return (0);
// }

