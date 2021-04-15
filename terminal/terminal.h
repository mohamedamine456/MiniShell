/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:17:07 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/15 12:08:59 by mlachheb         ###   ########.fr       */
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
}				t_flags;

char	*just_read();
int		get_termios(t_termios *term);
int		set_termios(t_termios *term, int flag);

#endif
