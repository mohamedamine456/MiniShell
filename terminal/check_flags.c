/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:29:53 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/19 12:36:43 by mlachheb         ###   ########.fr       */
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

void	apply_flags(char **buff, char *tmp, t_flags *fl)
{
	if (fl->esc == 1 && fl->l_br == 1 && ft_isalnum(fl->ltr))
	{
		if (fl->ltr == 'A')
		{
			clear_line();
			write(1, "up", 2);
		}
		else if (fl->ltr == 'B')
		{
			clear_line();
			write(1, "down", 4);
		}
		*fl = (t_flags){0, 0, 0};
	}
}
