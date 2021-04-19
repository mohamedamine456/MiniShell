/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:29:53 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/19 15:21:32 by mlachheb         ###   ########.fr       */
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

void	apply_flags(char **buff, char *tmp, t_flags *fl, t_history *hist)
{
	if (fl->esc == 1 && fl->l_br == 1 && ft_isalnum(fl->ltr))
	{
		if (fl->ltr == 'A')
		{
			if (hist->pos > 0)
			{
				clear_line();
				write(1, hist->tab_hist[hist->pos - 1], ft_strlen(hist->tab_hist[hist->pos - 1]));
				free(*buff);
				*buff = ft_strdup(hist->tab_hist[hist->pos - 1]);
				hist->pos -= 1;
			}
		}
		else if (fl->ltr == 'B')
		{
			if (hist->pos < hist->size)
			{
				clear_line();
				write(1, hist->tab_hist[hist->pos], ft_strlen(hist->tab_hist[hist->pos]));
				free(*buff);
				*buff = ft_strdup(hist->tab_hist[hist->pos]);
				hist->pos += 1;
			}

		}
		*fl = (t_flags){0, 0, 0};
	}
}
