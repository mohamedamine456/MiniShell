/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:57:36 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/19 17:05:39 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

void	up_arrow(t_history *hist, char **buff)
{
	int len;

	len = ft_strlen(*buff);
	if (hist->pos > 0 && (hist->wr == 0 || len == 0))
	{
		hist->wr = 0;
		clear_line();
		write(1, hist->tab_hist[hist->pos - 1], ft_strlen(hist->tab_hist[hist->pos - 1]));
		free(*buff);
		*buff = ft_strdup(hist->tab_hist[hist->pos - 1]);
		hist->pos -= 1;
	}

}

void	down_arrow(t_history *hist, char **buff)
{
	int len;

	len = ft_strlen(*buff);
	if (hist->pos < hist->size && (hist->wr == 0 || len == 0))
	{
		hist->wr = 0;
		clear_line();
		write(1, hist->tab_hist[hist->pos], ft_strlen(hist->tab_hist[hist->pos]));
		free(*buff);
		*buff = ft_strdup(hist->tab_hist[hist->pos]);
		hist->pos += 1;
	}
	else if (hist->pos == hist->size && (hist->wr == 0 || len == 0))
	{
		hist->wr = 0;
		clear_line();
		free(*buff);
		*buff = ft_strdup("");
	}
}
