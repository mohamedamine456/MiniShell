/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:17:07 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/19 14:39:21 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H
# include "../libft/libft.h"
# include "../structs.h"
# include <fcntl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# define TRUE 1

typedef struct termios t_termios;

typedef struct	s_flags
{
	int		esc;
	int		l_br;
	char	ltr;
}				t_flags;

/*
 * prototypes for read_line.c file
 */

char	*read_line(t_history *hist);
char	*just_read(t_history *hist);
char	*add_buffer(char *buff, char *tmp, t_flags *fl, t_history *hist);

/*
 * prototypes for check_flags.c file
 */

int		check_flags(char c, t_flags *fl);
void	apply_flags(char **buff, char *tmp, t_flags *fl, t_history *hist);

/*
 * prototypes for format_terminal.c file
 */

int		init_terminal_data();
int		format_terminal(t_termios *orig);
int		reset_terminal(t_termios *orig);
int		get_termios(t_termios *term);
int		set_termios(t_termios *term, int flag);

/*
 * prototypes for delete_char.c file
 */

void	delete_char(char **buff);
void    clear_line(void);

/*
 * prototypes for quit_d.c file
 */

void	quit_d(char *line);

#endif
