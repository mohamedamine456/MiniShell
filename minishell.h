#ifndef MINISHELL_H
# define MINISHELL_H
# define TRUE 1
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line/get_next_line.h"
# include "parse/parse.h"

typedef struct	s_general_data
{
	int		return_value;
	char	**envp;
	char	*shell_name;
}				t_generl_data;

#endif
