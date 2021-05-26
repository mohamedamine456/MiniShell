/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:05:06 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/26 13:19:50 by mlachheb         ###   ########.fr       */
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
		if (!ft_strcmp(g_hist.command_line, ""))
			quit_d(rt);
		return (g_hist.command_line);
	}
	else
	{
		delete_char(&(g_hist.command_line), rt);
		return (g_hist.command_line);
	}
}

/*
 * when ctrl+d hitted and buffer is empty free all and quit program
*/

void	quit_d(t_read_tools *rt)
{
	free(rt->tmp);
	ft_free_args(g_hist.tab_hist);
	close(g_hist.fd);
	write(1, "exit\n", 5);
	if (!reset_terminal(&(g_hist.orig)))
		exit(0);
	else
		exit(1);
}
