/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:32:24 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/17 12:43:59 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

char	*just_read(void)
{
	char	*buff;
	char	*tmp;
	t_flags	fl;

	fl = (t_flags){0, 0, 0, 0};
	buff = ft_strdup("");
	tmp = malloc(2);
	while (TRUE)
	{
		if (read(0, tmp, 1) > 0)
		{
			tmp[1] = '\0';
			if (tmp[0] == '\n')
				break ;
			buff = add_buffer(buff, tmp, &fl);
		}
		else
			break ;
	}
	free(tmp);
	return (buff);
}

char	*add_buffer(char *buff, char *tmp, t_flags *fl)
{
	int		arrows;
	static char	*spec = NULL;

	arrows = arrows_check(fl, tmp[0]);
	if (tmp[0] != 127 && tmp[0] != 27)
		return (ft_strjoin(buff, tmp));
	else
		return (buff);
}

int	arrows_check(t_flags *fl, char c)
{
	*fl = check_flags(*fl, c);
	if (compare_flags(*fl, (t_flags){1, 1, 'A', 0}))
	{
		write(1, "UP\n", 3);
	}
	else if (compare_flags(*fl, (t_flags){1, 1, 'B', 0}))
	{
		write(1, "DOWN\n", 5);
	}
	*fl = reset_flags(*fl, c);
	return (1);
}
