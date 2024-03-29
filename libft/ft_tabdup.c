/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:31:35 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/28 18:48:57 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **tab)
{
	char	**result;
	int		len;
	int		i;

	len = ft_strlen_tab(tab);
	len++;
	result = (char **)malloc(sizeof(char *) * len);
	i = 0;
	while (tab[i])
	{
		result[i] = ft_strdup(tab[i]);
		i++;
	}
	result[i] = NULL;
	return (result);
}
