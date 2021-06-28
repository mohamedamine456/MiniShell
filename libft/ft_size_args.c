/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:05:25 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/28 15:05:36 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * count the size of table of strings
*/

int	ft_size_args(char **tab)
{
	int	i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i] != NULL)
			i++;
	}
	return (i);
}
