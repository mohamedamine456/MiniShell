#ifndef MINISHELL_H
# define MINISHELL_H
# define TRUE 1
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line/get_next_line.h"
# include "parse/parse.h"
# include "terminal/terminal.h"
# include "structs.h"

typedef struct	s_general_data
{
	int		return_value;
	char	**envp;
}				t_general_data;


int				open_history(void);
void			write_history(t_history *hist, char *line);
t_history		read_history(int fd);

#endif
