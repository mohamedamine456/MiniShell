/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 09:27:19 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/28 15:55:58 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[++i] != '\0')
	{
		str[i] = s1[i];
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	free(s1);
	str[len] = '\0';
	return (str);
}
