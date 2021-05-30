/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_read_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:10:27 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/30 18:12:33 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

void	init_read_tools(t_read_tools *rt)
{
	rt->fl = (t_flags){0, 0, 0};
	g_data.nb_line = 0;
	rt->tmp = malloc(2);
	rt->new = new_hist();
	get_wininfo(&(rt->win_info));
	rt->capab.move_left = tgetstr("le", 0);
	rt->capab.del_one = tgetstr("dc", 0);
	rt->capab.up_line = tgetstr("up", 0);
	rt->capab.clear_ln = tgetstr("ce", 0);
	rt->capab.clear_scr = tgetstr("cd", 0);
}

int	get_wininfo(struct ttysize *win)
{
	if (ioctl(0, TIOCGWINSZ, win) == -1)
		return (-1);
	else
		return (0);
}
