/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:01:32 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/28 16:02:01 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strjoin_args(char **tab, char *str)
{
	int	i;

	i = 0;
	if (tab == NULL || str == NULL)
		return (NULL);
	while (tab[i] != NULL)
	{
		tab[i] = ft_strjoin(tab[i], str);
		i++;
	}
	free(str);
	return (tab);
}
