/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:57:36 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/21 16:33:12 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

/*
 * printed the previous item in history
 * if buff is empty or the buff contain a history item
*/

void	up_arrow(char **buff)
{
	int	len;

	len = ft_strlen(*buff);
	if (g_hist.pos > 0 && (g_hist.wr == 0 || len == 0))
	{
		g_hist.wr = 0;
		clear_line(*buff);
		write(1, g_hist.tab_hist[g_hist.pos - 1],
			ft_strlen(g_hist.tab_hist[g_hist.pos - 1]));
		free(*buff);
		*buff = ft_strdup(g_hist.tab_hist[g_hist.pos - 1]);
		g_hist.pos -= 1;
	}
}

/*
 * printed the next item in history
 * if buff is empty or the buff contain a history item
*/

void	down_arrow(char **buff)
{
	int	len;

	len = ft_strlen(*buff);
	if (g_hist.pos < g_hist.size && (g_hist.wr == 0 || len == 0))
	{
		g_hist.wr = 0;
		clear_line(*buff);
		write(1, g_hist.tab_hist[g_hist.pos],
			ft_strlen(g_hist.tab_hist[g_hist.pos]));
		free(*buff);
		*buff = ft_strdup(g_hist.tab_hist[g_hist.pos]);
		g_hist.pos += 1;
	}
	else if (g_hist.pos == g_hist.size && (g_hist.wr == 0 || len == 0))
	{
		g_hist.wr = 0;
		clear_line(*buff);
		free(*buff);
		*buff = ft_strdup("");
	}
}
