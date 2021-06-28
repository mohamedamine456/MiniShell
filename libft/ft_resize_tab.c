/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:05:47 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/28 15:04:33 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function to simply add a string to table of strings
*/

char	**ft_resize_tab(char **old, char *chaine)
{
	char	**new;
	int		i;
	int		len;

	i = 0;
	if (old == NULL)
		len = 0;
	else
		len = ft_size_args(old);
	new = (char **)malloc(sizeof(char *) * (len + 2));
	while (i < len)
	{
		new[i] = ft_strdup(old[i]);
		i++;
	}
	new[i] = ft_strdup(chaine);
	new[i + 1] = NULL;
	ft_free_args(old);
	free(chaine);
	return (new);
}
