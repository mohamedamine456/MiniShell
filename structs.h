#ifndef STRUCTS_H
# define STRUCTS_H
# include <termios.h>

typedef struct s_hisotry
{
	int				wr;
	int				fd;
	char			**tab_hist;
	int				size;
	int				pos;
	int				retv;
	char			*command_line;
	struct termios	orig;
}					t_history;

#endif
