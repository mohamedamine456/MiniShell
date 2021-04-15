/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:32:24 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/15 12:11:49 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

char	*just_read()
{
	char	*buff;
	char	*tmp;
	t_flags	fl;

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
			//fl = check_flags(fl, tmp[0]);
			buff = ft_strjoin(buff, tmp);
		}
		else
			break ;
	}
	free(tmp);
	return (buff);
}

t_flags		check_flags(t_flags fl, char c)
{
	if (c == 27)
	{
		if (fl.esc == 0)
			fl.esc = 1;
		else
			fl.esc = 0;
	}
	else if (c == 91 && fl.esc == 1)
		fl.l_br = 1;
	else if ((c == 'A' || c == 'B') && fl.esc == 1 && fl.l_br == 1)
		fl.ltr = c;
	return (fl);
}
