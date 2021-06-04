/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:05:21 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/04 11:00:29 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

void	signal_handler(void)
{
	if (signal(SIGINT, ctrl_c_handler) == SIG_ERR)
		exit(1);
	if (signal(SIGQUIT, ctrl_bs_handler) == SIG_ERR)
		exit(1);
	if (signal(SIGTSTP, ctrl_z_handler) == SIG_IGN)
		exit(1);
}

void	ctrl_c_handler(int sig)
{
	sig = 0;
	free(g_data.command_line);
	g_data.command_line = ft_strdup("");
	g_data.hists = last_hist(g_data.hists);
	g_data.nb_line = 0;
	write(1, "\n", 1);
	return ;
}

void	ctrl_bs_handler(int sig)
{
	sig = 0;
	free(g_data.command_line);
	g_data.command_line = ft_strdup("");
	g_data.hists = last_hist(g_data.hists);
	g_data.nb_line = 0;
	write(1, "Quit: 3\n", 8);
	return ;
}

void	ctrl_z_handler(int sig)
{
	return;
}
