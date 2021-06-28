/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:51:46 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/14 09:41:56 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		i;
	int		k;
	int		j;

	i = -1;
	k = 0;
	words = NULL;
	words = (char **)malloc((count_s((char *)s, c) + 1) * sizeof(char *));
	if (s == NULL || words == NULL)
		return (NULL);
	while (++i < count_s((char *)s, c))
	{
		j = -1;
		while (((char *)s)[k] == c)
			k++;
		words[i] = malloc(sizeof(char) * car_s((char *)s + k, c) + 1);
		while (++j < car_s((char *)s + k, c))
			words[i][j] = ((char *)s)[j + k];
		words[i][j] = '\0';
		k += j;
	}
	words[i] = 0;
	return (words);
}

int	count_s(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s != NULL && s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int	car_s(char *s, char c)
{
	int	i;

	i = 0;
	while (s != NULL && s[i] != c && s[i] != '\0')
		i++;
	return (i);
}
