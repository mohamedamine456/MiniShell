#ifndef PARSE_H
# define PARSE_H
# define SEPARATORS " \t\v\b><|;"
# include "../libft/libft.h"
# include "parse_structs.h"

int			parse_command(char *line, char **envp);

#endif
