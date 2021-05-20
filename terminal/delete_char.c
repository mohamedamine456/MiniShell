/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:45:06 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/20 16:32:48 by mlachheb         ###   ########.fr       */
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
	char	*start_line;
	char	*delete;

	len = ft_strlen(*buff);
	start_line = tgetstr("cr", 0);
	delete = tgetstr("ce", 0);
	if (len > 0)
	{
		(*buff)[len - 1] = '\0';
		tputs(start_line, 1, ft_putchar);
		tputs(delete, 1, ft_putchar);
		write(1, "MiniShell $> ", 13);
		write(1, *buff, ft_strlen(*buff));
	}
}

/*
 * clear_line: uses termcap to delete line from terminal
 * and prompt again
*/

void	clear_line(void)
{
	char	*start_line;
	char	*delete;

	start_line = tgetstr("cr", 0);
	delete = tgetstr("ce", 0);
	tputs(start_line, 1, ft_putchar);
	tputs(delete, 1, ft_putchar);
	write(1, "MiniShell $> ", 13);
}
