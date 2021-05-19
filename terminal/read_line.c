/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:03:45 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/19 08:56:03 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

char	*read_line(t_history *hist)
{
	if (!format_terminal(&(hist->orig)))
	{
		write(1, "MiniShell $> ", 13);
		g_hist.command_line = just_read(hist);
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

char	*just_read(t_history *hist)
{
	t_read_tools	rt;

	rt.fl = (t_flags){0, 0, 0};
	rt.line = ft_strdup("");
	g_hist.command_line = rt.line;
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
			rt.line = add_buffer(&rt, hist);
			g_hist.command_line = rt.line;
		}
		else
			break ;
	}
	free(rt.tmp);
	return (rt.line);
}

char	*add_buffer(t_read_tools *rt, t_history *hist)
{
	if (rt->tmp[0] == 4 || rt->tmp[0] == 127)
		return (quit_delete(rt, hist));
	else if (!check_flags(rt->tmp[0], &(rt->fl)))
	{
		hist->wr = 1;
		write(1, rt->tmp, 1);
		rt->line = ft_strjoin(rt->line, rt->tmp);
		return (rt->line);
	}
	else
	{
		apply_flags(&(rt->line), &(rt->fl), hist);
		return (rt->line);
	}
}
