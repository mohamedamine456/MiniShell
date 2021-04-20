/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:05:06 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/20 11:37:43 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

char	*quit_delete(t_read_tools *rt, t_history *hist)
{
	if (rt->tmp[0] == 4)
	{
		if (!ft_strcmp(rt->line, ""))
			quit_d(rt, hist);
		return (rt->line);
	}
	else
	{
		hist->wr = 1;
		delete_char(&(rt->line));
		return (rt->line);
	}
}

void	quit_d(t_read_tools *rt, t_history *hist)
{
	free(rt->line);
	free(rt->tmp);
	ft_free_args(hist->tab_hist);
	close(hist->fd);
	write(1, "exit\n", 5);
	exit(0);
}
