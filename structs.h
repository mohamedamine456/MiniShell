#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_hisotry
{
	int		wr;
	int		fd;
	char	**tab_hist;
	int		size;
	int		pos;
	int		retv;
	char	*command_line;
}				t_history;

#endif
