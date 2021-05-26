#ifndef STRUCTS_H
# define STRUCTS_H
# include <termios.h>

typedef struct s_hisotry
{
	int				fd;
	char			**tab_hist;
	int				size;
	int				pos;
	int				retv;
	int				nb_line;
	char			*command_line;
	struct termios	orig;
}					t_history;

t_history			g_hist;

#endif
