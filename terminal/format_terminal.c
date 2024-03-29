/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_terminal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:51:51 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/02 17:11:38 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

/*
 * look to terminal description before using termcap
*/

int	init_terminal_data(void)
{
	char	*termtype;
	char	*term_buffer;
	int		success;

	term_buffer = NULL;
	termtype = getenv("TERM");
	if (termtype == NULL)
		return (-1);
	success = tgetent(termtype, term_buffer);
	if (success < 0)
		return (-1);
	return (0);
}

/*
 * format_terminal: turn terminal to noncanonical mode
 * remove ECHO also to take care of printing characters
 * set VMIN to 1 and VTIME: to wait till one character is entered
*/

int	format_terminal(struct termios *orig)
{
	struct termios	term;

	if (init_terminal_data() == -1)
		return (-1);
	if (!get_termios(&term))
	{
		*orig = term;
		term.c_lflag &= ~ (ICANON | ECHO | ISIG);
		term.c_cc[VMIN] = 1;
		term.c_cc[VTIME] = 0;
		if (!set_termios(&term, TCSAFLUSH))
			return (0);
		return (-1);
	}
	return (-1);
}

/*
 *	reset terminal to old stat before format_terminal
*/

int	reset_terminal(struct termios *orig)
{
	if (!init_terminal_data())
	{
		if (!set_termios(orig, TCSAFLUSH))
			return (0);
	}
	return (-1);
}

int	get_termios(struct termios *term)
{
	if (tcgetattr(0, term) == -1)
		return (-1);
	else
		return (0);
}

int	set_termios(struct termios *term, int flag)
{
	if (tcsetattr(0, flag, term) == -1)
		return (-1);
	else
		return (0);
}
