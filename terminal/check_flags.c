/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:29:53 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/22 10:59:55 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int	check_ctrl(char c, t_flags *fl)
{
	return (0);
}

/*
 *	check_flags: check if the is esc followed by [ followed by letter
 *	if so we go to historique
*/

int	check_flags(char c, t_flags *fl)
{
	if (c >= 0 && c <= 31 && c != 4)
		return (1);
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
	else if (ft_isalnum(c) && fl->esc == 1 && fl->l_br == 1)
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

/*
 * apply_flags: check if esc+[+('A'|'B') is entered
 * is so calls up or down functions
*/

void	apply_flags(char **buff, t_flags *fl)
{
	if (fl->esc == 1 && fl->l_br == 1 && ft_isalnum(fl->ltr))
	{
		if (fl->ltr == 'A')
			up_arrow(buff);
		else if (fl->ltr == 'B')
			down_arrow(buff);
		*fl = (t_flags){0, 0, 0};
	}
}
