/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:05:06 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/21 16:31:56 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

/*
 * quit_delete function generate delete and ctrl+d keys
*/

char	*quit_delete(t_read_tools *rt)
{
	if (rt->tmp[0] == 4)
	{
		if (!ft_strcmp(rt->line, ""))
			quit_d(rt);
		return (rt->line);
	}
	else
	{
		g_hist.wr = 1;
		delete_char(&(rt->line));
		return (rt->line);
	}
}

/*
 * when ctrl+d hitted and buffer is empty free all and quit program
*/

void	quit_d(t_read_tools *rt)
{
	free(rt->line);
	free(rt->tmp);
	ft_free_args(g_hist.tab_hist);
	close(g_hist.fd);
	write(1, "exit\n", 5);
	if (!reset_terminal(&(g_hist.orig)))
		exit(0);
	else
		exit(1);
}
