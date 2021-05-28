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
# include "built_in/built_in.h"
# include "fork_commands/fork_commands.h"
# include "structs.h"

int				open_history(void);
void			write_history(t_general_data *hist, char *line);
t_general_data	read_history(int fd);
t_general_data	init_general_data();

int				parse_execute(char  *line, char ***envp, int retv);
int				split_commands(char **tab_cmds, char ***envp, int retv);

void			print_cmds(t_cmd *cmd);

#endif
