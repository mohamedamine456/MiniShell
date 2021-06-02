/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:29:53 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/02 17:28:47 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

/*
 *	check_flags: check if the is esc followed by [ followed by letter
 *	if so we go to historique
*/

int	check_flags(char c, t_flags *fl)
{
	if (c >= 0 && c <= 31 && c != 4 && c != 27)
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

void	apply_flags(t_read_tools *rt)
{	
	if (rt->fl.esc == 1 && rt->fl.l_br == 1 && ft_isalnum(rt->fl.ltr))
	{
		if (rt->fl.ltr == 'A')
			up_arrow(rt);
		else if (rt->fl.ltr == 'B')
			down_arrow(rt);
		rt->fl = (t_flags){0, 0, 0};
	}
	else if (rt->tmp[0] == 3)
		intern_ctrl_c();
}

void	intern_ctrl_c(void)
{
	free(g_data.command_line);
	g_data.command_line = ft_strdup("");
	g_data.hists = last_hist(g_data.hists);
	g_data.nb_line = 0;
	write(1, "\nMinishell $> ", 14);
	return ;
}
