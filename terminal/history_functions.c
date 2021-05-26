/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:57:36 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/26 14:00:27 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

/*
 * printed the previous item in history
 * if buff is empty or the buff contain a history item
 */

void	up_arrow(char **buff, t_read_tools *rt)
{
	int	len;

	len = ft_strlen(*buff);
	if (g_hist.pos > 0)
	{
		clear_line(*buff, rt);
		write(1, g_hist.tab_hist[g_hist.pos - 1],
				ft_strlen(g_hist.tab_hist[g_hist.pos - 1]));
		free(*buff);
		*buff = ft_strdup(g_hist.tab_hist[g_hist.pos - 1]);
		g_hist.pos -= 1;
	}
	rt->nb_line = (ft_strlen(g_hist.command_line) - 1) / rt->win_info.ts_cols;
}

/*
 * printed the next item in history
 * if buff is empty or the buff contain a history item
 */

void	down_arrow(char **buff, t_read_tools *rt)
{
	int	len;

	len = ft_strlen(*buff);
	if (g_hist.pos < g_hist.size)
	{
		clear_line(*buff, rt);
		write(1, g_hist.tab_hist[g_hist.pos],
				ft_strlen(g_hist.tab_hist[g_hist.pos]));
		free(*buff);
		*buff = ft_strdup(g_hist.tab_hist[g_hist.pos]);
		g_hist.pos += 1;
	}
	rt->nb_line = (ft_strlen(g_hist.command_line) - 1) / rt->win_info.ts_cols;
}

void   write_history_line()
{
	if (!ft_strcmp(g_hist.command_line, ""))
	{
		g_hist.tab_hist = ft_resize_tab(g_hist.tab_hist, ft_strdup(""));
		g_hist.pos += 1;
		g_hist.size += 1;
	}
	else
	{
		free(g_hist.tab_hist[g_hist.pos - 1]);
		g_hist.tab_hist[g_hist.pos - 1] = ft_strdup(g_hist.command_line);
	}
}
