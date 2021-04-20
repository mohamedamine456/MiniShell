/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:03:45 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/20 16:03:56 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

char	*read_line(t_history *hist)
{
	t_termios	orig;
	char		*cmd_line;

	if (!format_terminal(&orig))
	{
		write(1, "MiniShell $> ", 13);
		cmd_line = just_read(hist);
		return (cmd_line);
	}
	return (NULL);
}

char	*just_read(t_history *hist)
{
	t_read_tools	rt;

	rt.fl = (t_flags){0, 0, 0};
	rt.line = ft_strdup("");
	rt.tmp = malloc(2);
	while (TRUE)
	{
		if (read(0, rt.tmp, 1) > 0)
		{	
			rt.tmp[1] = '\0';
			if (rt.tmp[0] == '\n')
				break ;
			rt.line = add_buffer(&rt, hist);
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
		apply_flags(&(rt->line), rt->tmp, &(rt->fl), hist);
		return (rt->line);
	}
}
