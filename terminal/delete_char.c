/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:45:06 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/25 14:57:40 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

/*
 * delete_char: uses termcap capabilities to:
 * move the cursor to left one character with 'le' capability
 * delete character on right with 'dc' capability
 * only if buffer contain enough characters
*/

void	delete_char(char **buff)
{
	int		len;
	char	*move_left;
	char	*del_one;

	len = ft_strlen(*buff);
	move_left = tgetstr("le", 0);
	del_one = tgetstr("dc", 0);
	if (len > 0)
	{
		(*buff)[len - 1] = '\0';
		tputs(move_left, 1, ft_putchar);
		tputs(del_one, 1, ft_putchar);
	}
}

/*
 * clear_line: uses termcap to delete line from terminal
 * and prompt again
*/

void	clear_line(char *buff)
{
	int		len;
	char	*move_left;
	char	*delete;
	
	len = ft_strlen(buff);
	move_left = tgetstr("le", 0);
	delete = tgetstr("ce", 0);
	while (len > 0)
	{
		tputs(move_left, 1, ft_putchar);
		len--;
	}
	tputs(delete, 1, ft_putchar);
}
