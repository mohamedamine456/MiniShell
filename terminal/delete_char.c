/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:45:06 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/30 18:07:09 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

/*
 * delete_char: uses termcap capabilities to:
 * move the cursor to left one character with 'le' capability
 * delete character on right with 'dc' capability
 * only if buffer contain enough characters
*/

void	delete_char(char **buff, t_read_tools *rt)
{
	int	len;

	len = ft_strlen(*buff);
	if (len > 0)
	{
		(*buff)[len - 1] = '\0';
		tputs(rt->capab.move_left, 1, ft_putchar);
		tputs(rt->capab.del_one, 1, ft_putchar);
		if (g_data.hists->line_chngd != NULL)
			free(g_data.hists->line_chngd);
		g_data.hists->line_chngd = ft_strdup(*buff);
	}
	g_data.nb_line = (ft_strlen(g_data.command_line) - 1) / rt->win_info.ts_cols;
}

/*
 * clear_line: uses termcap to delete line from terminal
 * and prompt again
*/

void	clear_line(char *buff, t_read_tools *rt)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(buff);
	while (i < g_data.nb_line)
	{
		tputs(rt->capab.up_line, 1, ft_putchar);
		len -= rt->win_info.ts_cols;
		i++;
	}
	g_data.nb_line = 0;
	while (len > 0)
	{
		tputs(rt->capab.move_left, 1, ft_putchar);
		len--;
	}
	tputs(rt->capab.clear_scr, 1, ft_putchar);
}
