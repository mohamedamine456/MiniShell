/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:29:53 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/15 16:19:41 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int		compare_flags(t_flags fl1, t_flags fl2)
{
	if (fl1.esc != fl2.esc)
		return (0);
	else if (fl1.l_br != fl2.l_br)
		return (0);
	else if (fl1.ltr != fl2.ltr)
		return (0);
	return (1);
}

t_flags	check_flags(t_flags fl, char c)
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

t_flags reset_flags(t_flags fl, char c)
{
	if (!compare_flags(fl, (t_flags){0, 0, 0}))
	{
		if (c != 27 && c != 91 && c != 'A' && c != 'B')
			fl = (t_flags){0, 0, 0};
	}
	else if (compare_flags(fl, (t_flags){1, 1, 'A'}))
			fl = (t_flags){0, 0, 0};
	else if (compare_flags(fl, (t_flags){1, 1, 'B'}))
			fl = (t_flags){0, 0, 0};
	return (fl);
}
