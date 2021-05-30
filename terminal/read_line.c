/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:03:45 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/30 12:14:55 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

char *read_line()
{
	t_read_tools rt;

	if (!format_terminal(&(g_data.orig)))
	{
		init_read_tools(&rt);
		write(1, "MiniShell $> ", 13);
		g_data.command_line = just_read(&rt);
		if (check_line_errors(g_data.command_line) == -1)
		{
			free(g_data.command_line);
			g_data.command_line = NULL;
			reset_terminal(&(g_data.orig));
			free(rt.tmp);
			write(1, "Close all quotes, no backslash at the end of line!\n", 52);
			return (NULL);
		}
		reset_terminal(&(g_data.orig));
		free(rt.tmp);
		return (g_data.command_line);
	}
	free(rt.tmp);
	return (NULL);
}

char *just_read(t_read_tools *rt)
{
	g_data.command_line = ft_strdup("");
	rt->new->line_orig = ft_strdup("");
	add_back_hist(&(g_data.hists), rt->new);
	g_data.hists = last_hist(g_data.hists);
	while (TRUE)
	{
		if (read(0, rt->tmp, 1) > 0)
		{
			rt->tmp[1] = '\0';
			if (rt->tmp[0] == '\n')
			{
				write(1, "\n", 1);
				break;
			}
			g_data.command_line = add_buffer(rt);
		}
		else
			break;
	}
	return (g_data.command_line);
}

char *add_buffer(t_read_tools *rt)
{
	if (rt->tmp[0] == 4 || rt->tmp[0] == 127)
	{
		g_data.command_line = quit_delete(rt);
	}
	else if (!check_flags(rt->tmp[0], &(rt->fl)))
	{
		write(1, rt->tmp, 1);
		g_data.command_line = ft_strjoin(g_data.command_line, rt->tmp);
		write_history_line();
		g_data.nb_line = (ft_strlen(g_data.command_line) - 1) / rt->win_info.ts_cols;
	}
	else
	{
		apply_flags(rt);
	}
	return (g_data.command_line);
}
