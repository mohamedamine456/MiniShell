/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:46:54 by mlachheb          #+#    #+#             */
/*   Updated: 2021/07/01 12:02:43 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int	check_line_errors(char *line)
{
	int			i;
	t_escapes	escp;

	i = 0;
	escp = (t_escapes){0, 0, 0};
	while (line != NULL && line[i] != '\0')
	{
		escp = ft_check_escapes(escp, line[i]);
		if (escp.s_q % 2 == 0 && escp.d_q % 2 == 0
			&& escp.b_s == 0 && line[i] == ';')
		{
			return (-1);
		}
		if (line[i] != '\\' && escp.b_s == 1)
			escp.b_s = 0;
		i++;
	}
	if (escp.b_s == 1 || escp.s_q % 2 != 0 || escp.d_q % 2 != 0)
		return (-1);
	return (0);
}

void	free_last_hist(void)
{
	g_data.hists = g_data.hists->previous;
	if (g_data.hists->next->line_orig != NULL)
		free(g_data.hists->next->line_orig);
	if (g_data.hists->next->line_chngd != NULL)
		free(g_data.hists->next->line_chngd);
	free(g_data.hists->next);
	g_data.hists->next = NULL;
}

void	line_error(t_read_tools rt)
{
	free(g_data.command_line);
	g_data.command_line = NULL;
	reset_terminal(&(g_data.orig));
	free(rt.tmp);
	if (g_data.hists->next == NULL)
		free_last_hist();
	g_data.hists = last_hist(g_data.hists);
	if (!ft_strcmp(g_data.hists->line_orig, "")
		&& g_data.hists->line_chngd == NULL)
		free_last_hist();
	write(1, "Close all quotes, No MultiCommands,", 35);
	write(1, " No backslash at the end of line!\n", 34);
	g_data.retv = 1;
}
