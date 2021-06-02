/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:17:07 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/02 17:28:04 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H
# include "../structs.h"
# include "../minishell.h"
# include <sys/ioctl.h>
# include <fcntl.h>
# include <curses.h>
# include <term.h>
# define TRUE 1

typedef struct s_flags
{
	int		esc;
	int		l_br;
	char	ltr;
}				t_flags;

typedef struct s_termcapab
{
	char		*move_left;
	char		*del_one;
	char		*up_line;
	char		*clear_ln;
	char		*clear_scr;
}				t_termcapab;

typedef struct s_read_tools
{
	struct ttysize	win_info;
	t_termcapab		capab;
	char			*tmp;
	t_history		*new;
	t_flags			fl;
}				t_read_tools;

/*
 * prototypes for read_line.c file
 */

char	*read_line(void);
char	*just_read(t_read_tools *rt);
char	*add_buffer(t_read_tools *rt);

/*
 * prototypes for check_flags.c file
 */

int		check_flags(char c, t_flags *fl);
void	apply_flags(t_read_tools *rt);
void	intern_ctrl_c(void);

/*
 * prototypes for format_terminal.c file
 */

int		init_terminal_data(void);
int		format_terminal(struct termios *orig);
int		reset_terminal(struct termios *orig);
int		get_termios(struct termios *term);
int		set_termios(struct termios *term, int flag);

/*
 * prototypes for delete_char.c file
 */

void	delete_char(char **buff, t_read_tools *rt);
void	clear_line(char *buff, t_read_tools *rt);

/*
 * prototypes for quit_d.c file
 */

void	quit_d(t_read_tools *rt);
char	*quit_delete(t_read_tools *rt);

/*
 * prototypes for history_functions.c file
 */

void	up_arrow(t_read_tools *rt);
void	down_arrow(t_read_tools *rt);
void	write_history_line(void);

/*
 * prototypes for init_read_tools.c file
 */

void	init_read_tools(t_read_tools *rt);
int		get_wininfo(struct ttysize *win);

/*
 * prototypes for signal_handler.c file
 */

void	signal_handler(void);
void	ctrl_c_handler(int sig);
void	ctrl_bs_handler(int sig);
void	ctrl_anon(int sig);

/*
 * prototypes for check_line_errors.c file
 */

int		check_line_errors(char *line);

#endif
