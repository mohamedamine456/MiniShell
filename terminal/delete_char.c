/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:45:06 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/17 17:02:27 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

void	delete_char(char **buff)
{
	int		len;
	char	*move_left;
	char	*clear;

	len = ft_strlen(*buff);
	move_left = tgetstr("le", 0);
	clear = tgetstr("ce", 0);
	tputs(move_left, 1, ft_putchar);
	tputs(clear, 1, ft_putchar);
	if (len > 0)
	{
		(*buff)[len - 1] = '\0';
		tputs(move_left, 1, ft_putchar);
		tputs(clear, 1, ft_putchar);
	}
}
