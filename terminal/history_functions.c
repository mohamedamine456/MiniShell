/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:57:36 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/26 21:27:59 by mlachheb         ###   ########.fr       */
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
	int	len2;

	len = ft_strlen(*buff);
	if (g_hist.pos > 0)
	{
		g_hist.pos -= 1;
		len2 = ft_strlen(g_hist.tab_hist[g_hist.pos]);
		clear_line(*buff, rt);
		write(1, g_hist.tab_hist[g_hist.pos], len2);
		free(*buff);
		*buff = ft_strdup(g_hist.tab_hist[g_hist.pos]);
	}
	g_hist.nb_line = (ft_strlen(g_hist.command_line) - 1) / rt->win_info.ts_cols;
}

/*
 * printed the next item in history
 * if buff is empty or the buff contain a history item
 */

void	down_arrow(char **buff, t_read_tools *rt)
{
	int	len;
	int	len2;

	len = ft_strlen(*buff);
	if (g_hist.pos < g_hist.size - 1)
	{
		g_hist.pos += 1;
		len2 = ft_strlen(g_hist.tab_hist[g_hist.pos]);
		clear_line(*buff, rt);
		write(1, g_hist.tab_hist[g_hist.pos], len2);
		free(*buff);
		*buff = ft_strdup(g_hist.tab_hist[g_hist.pos]);
	}
	g_hist.nb_line = (ft_strlen(g_hist.command_line) - 1) / rt->win_info.ts_cols;
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
