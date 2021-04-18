/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_terminal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:51:51 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/18 16:52:12 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int		init_terminal_data()
{
	char    *termtype;
	char    *term_buffer;
	int             success;

	term_buffer = NULL;
	termtype = getenv("TERM");
	if (termtype == NULL)
		return (-1);
	success = tgetent(termtype, term_buffer);
	if (success < 0)
		return (-1);
	return (0);
}

int		format_terminal(t_termios *orig)
{
	t_termios	term;

	if (init_terminal_data() == -1)
		return (-1);
	if (!get_termios(&term))
	{
		*orig = term;
		term.c_lflag &= ~(ICANON | ECHO);
		term.c_cc[VMIN] = 1;
		term.c_cc[VTIME] = 0;
		if (!set_termios(&term, TCSAFLUSH))
			return (0);
		return (-1);
	}
	return (-1);
}

int		rest_terminal(t_termios *orig)
{
	if (!set_termios(orig, TCSANOW))
		return (0);
	return (-1);
}
