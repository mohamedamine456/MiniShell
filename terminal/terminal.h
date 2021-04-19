/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:17:07 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/19 11:15:33 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# define TRUE 1

typedef struct termios	t_termios;

typedef struct	s_flags
{
	int		esc;
	int		l_br;
	char	ltr;
}				t_flags;

int		init_terminal_data();

char	*read_line();
char	*just_read();
int		get_termios(t_termios *term);
int		set_termios(t_termios *term, int flag);

char	*add_buffer(char *buff, char *tmp, t_flags *fl);

int		compare_flags(t_flags fl1, t_flags fl2);
int		check_flags(char c, t_flags *fl);
t_flags	reset_flags(t_flags fl, char c);
void	apply_flags(char **buff, char *tmp, t_flags fl);

int		format_terminal(t_termios *orig);
int		reset_terminal(t_termios *orig);

void	delete_char(char **buff);
void	quit_d(char *line);

void    print_termios(t_termios term);

#endif
