/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:45:06 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/18 16:59:59 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

void	delete_char(char **buff)
{
	int		len;
	char	*move_left;
	char	*del_one;
	char	*clear;
	char	*beg_line;

	len = ft_strlen(*buff);
	move_left = tgetstr("le", 0);
	del_one = tgetstr("dc", 0);
	beg_line = tgetstr("cr", 0);
	clear = tgetstr("dl", 0);
	//tputs(beg_line, 1, ft_putchar);
	if (len > 0)
	{
		(*buff)[len - 1] = '\0';
		tputs(move_left, 1, ft_putchar);
		tputs(del_one, 1, ft_putchar);
	}
	//tputs(clear, 1, ft_putchar);
}
