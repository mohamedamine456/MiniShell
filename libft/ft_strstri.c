/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:47:52 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/28 15:57:32 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Same as strstr but it returns the index of
 * the first character of needle in the haystack 
 */

int	ft_strstri(const char *haystack, const char *needle)
{
	int	i;
	int	found;
	int	j;
	int	len;

	i = -1;
	if (*needle == '\0' || *haystack == '\0')
		return (-1);
	len = ft_strlen(haystack);
	while (ft_strlen((char *)needle) + (++i) <= len)
	{
		j = 0;
		if (haystack[i + j] == needle[j])
		{
			found = 1;
			while (j < ft_strlen((char *)needle) && found == 1)
			{
				if (haystack[i + j] != needle[j])
					found = 0;
				if (j++ == (ft_strlen((char *)needle) - 1) && found == 1)
					return (i);
			}
		}
	}
	return (-1);
}
