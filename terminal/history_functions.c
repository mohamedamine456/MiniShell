/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:57:36 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/19 15:06:20 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

void	up_arrow(t_history *hist)
{
	if (hist->pos > 0)
	{
		clear_line();
		write(1, hist->tab_hist[pos -1], ft_strlen(hist->tab_hist[pos - 1]));
		hist->pos -= 1;
	}
}
