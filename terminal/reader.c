/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:32:24 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/15 16:53:12 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

char	*just_read()
{
	char	*buff;
	char	*tmp;
	t_flags	fl;
	int		arrow;

	fl = (t_flags){0, 0, 0};
	buff = ft_strdup("");
	tmp = malloc(2);
	while (TRUE)
	{
		if (read(0, tmp, 1) > 0)
		{
			tmp[1] = '\0';
			if (tmp[0] == '\n')
				break ;
			arrow = arrows_check(&fl, tmp[0]);
			buff = ft_strjoin(buff, tmp);
		}
		else
			break ;
	}
	free(tmp);
	return (buff);
}

int			arrows_check(t_flags *fl, char c)
{
	*fl = check_flags(*fl, c);
	if (compare_flags(*fl, (t_flags){1, 1, 'A'}))
	{
		write(1, "UP\n", 3);
	}
	else if (compare_flags(*fl, (t_flags){1, 1, 'B'}))
	{
		write(1, "DOWN\n", 5);
	}
	*fl = reset_flags(*fl, c);
	return (1);
}
