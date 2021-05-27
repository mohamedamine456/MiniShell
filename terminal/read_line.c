/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:03:45 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/27 16:26:21 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

char	*read_line()
{
	t_read_tools	rt;

	if (!format_terminal(&(g_hist.orig)))
	{
		init_read_tools(&rt);
		write(1, "MiniShell $> ", 13);
		g_hist.command_line = just_read(&rt);
		if (check_line_errors(g_hist.command_line) == -1)
		{
			free(g_hist.command_line);
			g_hist.command_line = NULL;
			reset_terminal(&(g_hist.orig));
			free(rt.tmp);
			write(1, "Close all quotes, no backslash at the end of line!\n", 52);
			return (NULL);
		}
		reset_terminal(&(g_hist.orig));
		free(rt.tmp);
		return (g_hist.command_line);
	}
	free(rt.tmp);
	return (NULL);
}

char	*just_read(t_read_tools *rt)
{
	g_hist.command_line = ft_strdup("");
	g_hist.tab_hist = ft_resize_tab(g_hist.tab_hist, ft_strdup(""));
	g_hist.pos += 1;
	g_hist.size += 1;
	while (TRUE)
	{
		if (read(0, rt->tmp, 1) > 0)
		{	
			rt->tmp[1] = '\0';
			if (rt->tmp[0] == '\n')
			{
				write(1, "\n", 1);
				break ;
			}
			g_hist.command_line = add_buffer(rt);
		}
		else
			break ;
	}	
	return (g_hist.command_line);
}

char	*add_buffer(t_read_tools *rt)
{
	int	var;

	if (rt->tmp[0] == 4 || rt->tmp[0] == 127)
	{
		write_history_line();
		g_hist.command_line = quit_delete(rt);
	}
	else if (!check_flags(rt->tmp[0], &(rt->fl)))
	{
		write(1, rt->tmp, 1);
		g_hist.command_line = ft_strjoin(g_hist.command_line, rt->tmp);
		write_history_line();
		g_hist.nb_line = (ft_strlen(g_hist.command_line) - 1) / rt->win_info.ts_cols;
	}
	else
	{
		apply_flags(&(g_hist.command_line), rt);
	}
	return (g_hist.command_line);
}
