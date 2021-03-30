#ifndef STRUCTS_H
# define STRUCTS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_cmd
{
	char			*name;
	char			*option;
	char			**output;
	char			**input;
	char			**args;
	struct s_cmd	*next;
}					t_cmd;

#endif
