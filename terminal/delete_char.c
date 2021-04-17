/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:45:06 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/17 16:20:20 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

void	delete_char(char **buff)
{
	int		len;
	char	*move_left;
	char	*del_one;

	len = ft_strlen(*buff);
	move_left = tgetstr("le", 0);
	del_one = tgetstr("dc", 0);
	tputs(move_left, 1, ft_putchar);
	tputs(del_one, 1, ft_putchar);
	if (len > 0)
	{
		(*buff)[len - 1] = '\0';
		tputs(move_left, 1, ft_putchar);
		tputs(del_one, 1, ft_putchar);
	}
}
