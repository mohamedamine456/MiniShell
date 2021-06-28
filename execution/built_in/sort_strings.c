/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:43:10 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/28 17:05:01 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	sort_strings(char **table)
{
	char	*tmp;
	int		index;
	int		j;
	int		table_len;

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
