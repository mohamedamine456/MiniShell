/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:57:36 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/29 20:21:59 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

/*
 * printed the previous item in history
 * if buff is empty or the buff contain a history item
 */

void up_arrow(char **buff, t_read_tools *rt)
{
	int len2;

	if(g_data.hists->previous != NULL)
	{
		g_data.hists = g_data.hists->previous;
		clear_line(*buff, rt);
		free(*buff);
		if (g_data.hists->line_chngd != NULL)
			*buff = ft_strdup(g_data.hists->line_chngd);
		else
			*buff = ft_strdup(g_data.hists->line_orig);
		len2 = ft_strlen(*buff);
		write(1, *buff, len2);
		g_data.nb_line = (ft_strlen(*buff) - 1) / rt->win_info.ts_cols;
	}
}

/*
 * printed the next item in history
 * if buff is empty or the buff contain a history item
 */

void down_arrow(char **buff, t_read_tools *rt)
{
	int len2;

	if (g_data.hists->next != NULL)
	{
		g_data.hists = g_data.hists->next;
		clear_line(*buff, rt);
		free(*buff);
		if (g_data.hists->line_chngd != NULL)
			*buff = ft_strdup(g_data.hists->line_chngd);
		else
			*buff = ft_strdup(g_data.hists->line_orig);
		len2 = ft_strlen(*buff);
		write(1, g_data.hists->line_orig, len2);
		g_data.nb_line = (ft_strlen(*buff) - 1) / rt->win_info.ts_cols;
	}
}

void	write_history_line()
{
	if (g_data.hists->line_orig != NULL)
		g_data.hists->line_chngd = ft_strdup(g_data.command_line);
	else
		g_data.hists->line_orig = ft_strdup(g_data.command_line);
}
