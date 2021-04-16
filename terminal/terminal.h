/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:17:07 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/16 15:27:36 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H
# include <fcntl.h>
# include <termios.h>
# include "../libft/libft.h"
# define TRUE 1

typedef struct termios	t_termios;

typedef struct	s_flags
{
	int		esc;
	int		l_br;
	char	ltr;
	int		del;
}				t_flags;

char	*just_read();
int		get_termios(t_termios *term);
int		set_termios(t_termios *term, int flag);

int		arrows_check(t_flags *fl, char c);
char	*add_buffer(char *buff, char *tmp, t_flags *fl);

int		compare_flags(t_flags fl1, t_flags fl2);
t_flags	check_flags(t_flags fl, char c);
t_flags	reset_flags(t_flags fl, char c);

int		format_terminal(t_termios *orig);
int		rest_terminal(t_termios *orig);

#endif
