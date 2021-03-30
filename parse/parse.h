#ifndef PARSE_H
# define PARSE_H
# define SEPARATORS " \t\v\b><|;"
# include "../libft/libft.h"
# include "parse_structs.h"
# include "cmd.h"

int			parse_command(char *line, char **envp);
t_cmd 	*new_cmd(t_cmd cmd);
void	print_cmd(t_cmd cmd);
void	cmd_add_back(t_cmd **cmd, t_cmd *new);
#endif
