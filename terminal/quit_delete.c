/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:05:06 by mlachheb          #+#    #+#             */
/*   Updated: 2021/07/02 13:03:56 by mlachheb         ###   ########.fr       */
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
		if (!ft_strcmp(g_data.command_line, ""))
			quit_d(rt);
		return (g_data.command_line);
	}
	else
	{
		delete_char(&(g_data.command_line), rt);
		return (g_data.command_line);
	}
}

/*
 * when ctrl+d hitted and buffer is empty free all and quit program
*/

void	quit_d(t_read_tools *rt)
{
	free(rt->tmp);
	free(g_data.command_line);
	close(g_data.fd);
	clear_hist(&(g_data.hists));
	write(1, "exit\n", 5);
	if (!reset_terminal(&(g_data.orig)))
	{
		exit(g_data.retv);
	}
	else
		exit(1);
}
