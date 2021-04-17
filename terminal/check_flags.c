/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:29:53 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/17 13:47:33 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int		check_flags(char c, t_flags *fl)
{
	if (c == 27)
	{
		if (fl->esc == 0)
			fl->esc = 1;
		else
			fl->esc = 0;
		return (1);
	}
	else if (c == 91 && fl->esc == 1)
	{
		fl->l_br = 1;
		return (1);
	}
	else if ((c == 'A' || c == 'B') && fl->esc == 1 && fl->l_br == 1)
	{
		fl->ltr = c;
		return (1);
	}
	else
	{
		*fl = (t_flags){0, 0, 0};
		return (0);
	}
}

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

t_flags reset_flags(t_flags fl, char c)
{
	if (!compare_flags(fl, (t_flags){0, 0, 0}))
	{
		if (c != 27 && c != 91 && c != 'A' && c != 'B')
			fl = (t_flags){0, 0, 0};
	}
	if (compare_flags(fl, (t_flags){1, 1, 'A'}))
			fl = (t_flags){0, 0, 0};
	if (compare_flags(fl, (t_flags){1, 1, 'B'}))
			fl = (t_flags){0, 0, 0};
	return (fl);
}

void	apply_flags(char **buff, char *tmp, t_flags fl)
{

}
