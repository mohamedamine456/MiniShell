/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:34:08 by mlachheb          #+#    #+#             */
/*   Updated: 2020/10/29 17:35:51 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	char			*str;
	static char		*grd = 0;
	int				r;
	char			*tmp;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (grd == 0)
		grd = ft_strdup("");
	while (!(check_end_line(grd)))
	{
		r = read(fd, str, BUFFER_SIZE);
		str[r] = '\0';
		tmp = grd;
		grd = ft_resize(str, grd);
		free(tmp);
		tmp = NULL;
		if (r == 0)
			break ;
	}
	free(str);
	str = NULL;
	return (make_line(&grd, line));
}

int			make_line(char **grd, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	if (check_end_line(*grd) != 0)
	{
		while ((*grd)[i] != '\n')
			i++;
	}
	if (check_end_line(*grd))
	{
		tmp = *line;
		*line = ft_substr(*grd, 0, i);
		tmp = *grd;
		*grd = ft_strdup(*grd + i + 1);
		free(tmp);
		return (1);
	}
	*line = ft_strdup(*grd);
	free(*grd);
	*grd = NULL;
	return (0);
}

char		*ft_resize(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s2 != 0)
	{
		s = malloc(ft_strlen(s2) + BUFFER_SIZE + 1);
		while (s2[i] != '\0')
		{
			s[i] = s2[i];
			i++;
		}
	}
	else
		s = malloc(BUFFER_SIZE + 1);
	while (s1[j] != '\0')
	{
		s[i] = s1[j];
		i++;
		j++;
	}
	s[i] = '\0';
	return (s);
}

int			check_end_line(char *str)
{
	int i;

	i = 0;
	if (str != 0)
		while (str[i] != '\0')
		{
			if (str[i] == '\n')
				return (1);
			i++;
		}
	return (0);
}