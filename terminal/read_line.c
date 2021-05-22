/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:03:45 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/22 10:59:57 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

char	*read_line()
{
	if (!format_terminal(&(g_hist.orig)))
	{
		write(1, "MiniShell $> ", 13);
		g_hist.command_line = just_read();
		if (check_line_errors(g_hist.command_line) == -1)
		{
			free(g_hist.command_line);
			g_hist.command_line = NULL;
			write(1, "Close all quotes, no backslash at the end of line!\n", 52);
			return (NULL);
		}
		return (g_hist.command_line);
	}
	return (NULL);
}

char	*just_read()
{
	t_read_tools	rt;

	rt.fl = (t_flags){0, 0, 0};
	g_hist.command_line = ft_strdup("");
	rt.tmp = malloc(2);
	while (TRUE)
	{
		if (read(0, rt.tmp, 1) > 0)
		{	
			rt.tmp[1] = '\0';
			if (rt.tmp[0] == '\n')
			{
				write(1, "\n", 1);
				break ;
			}
			g_hist.command_line = add_buffer(&rt);
		}
		else
			break ;
	}
	free(rt.tmp);
	return (g_hist.command_line);
}

char	*add_buffer(t_read_tools *rt)
{
	if (rt->tmp[0] == 4 || rt->tmp[0] == 127)
		return (quit_delete(rt));
	else if (!check_flags(rt->tmp[0], &(rt->fl)))
	{
		g_hist.wr = 1;
		write(1, rt->tmp, 1);
		g_hist.command_line = ft_strjoin(g_hist.command_line, rt->tmp);
		return (g_hist.command_line);
	}
	else
	{
		apply_flags(&(g_hist.command_line), &(rt->fl));
		return (g_hist.command_line);
	}
}
