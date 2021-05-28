#ifndef STRUCTS_H
# define STRUCTS_H
# include <termios.h>

typedef struct s_history
{
	char				*line_orig;
	char				*line_chngd;
	struct s_histroy	*next;
	struct s_history	*previous;
}						t_history;

typedef struct s_general_data
{
	int				fd;
	t_history		*line_hist;
	char			**tab_hist;
	int				size;
	int				pos;
	int				retv;
	int				nb_line;
	char			*command_line;
	struct termios	orig;
}					t_general_data;

t_general_data		g_data;

#endif
