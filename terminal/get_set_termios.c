/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set_termios.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:14:32 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/15 12:08:50 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int	get_termios(t_termios *term)
{
	if (tcgetattr(0, term) == -1)
		return (-1);
	else
		return (0);
}

int	set_termios(t_termios *term, int flag)
{
	if (tcsetattr(0, flag, term) == -1)
		return (-1);
	else
		return (0);
}
