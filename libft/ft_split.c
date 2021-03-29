/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 09:26:48 by mlachheb          #+#    #+#             */
/*   Updated: 2021/02/09 09:26:50 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_s(char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	car_s(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static void	free_all(char **words, int i)
{
	while (i >= 0)
	{
		free(words[i]);
		i--;
	}
	free(words);
}

char		**ft_split(char const *s, char c)
{
	char	**words;
	int		i;
	int		k;
	int		j;

	i = -1;
	k = 0;
	words = NULL;
	if (s == NULL || !(words = (char **)malloc((count_s((char *)s,
							c) + 1) * sizeof(char *))))
		return (NULL);
	while (++i < count_s((char *)s, c))
	{
		j = -1;
		while (((char *)s)[k] == c)
			k++;
		if (!(words[i] = malloc(sizeof(char) * car_s((char *)s + k, c) + 1)))
			free_all(words, i);
		while (++j < car_s((char *)s + k, c))
			words[i][j] = ((char *)s)[j + k];
		words[i][j] = '\0';
		k += j;
	}
	words[i] = 0;
	return (words);
}
