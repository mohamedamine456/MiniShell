#ifndef MINISHELL_H
# define MINISHELL_H
# define TRUE 1
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "get_next_line/get_next_line.h"
# include "parse/parse.h"
# include "terminal/terminal.h"
# include "execution/execution.h"
# include "fork_commands/fork_commands.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "structs.h"

int				open_history(void);
void			write_history(t_general_data *hist, char *line);
t_general_data	read_history(int fd);
t_general_data	init_general_data();
t_history		*read_hists(int fd);

int				parse_execute(char  *line, char ***envp, int retv);
int				split_commands(char **tab_cmds, char ***envp, int retv);

void			print_cmds(t_cmd *cmd);

/*
 * prototypes for hist_functions.c file
 */

void		add_back_hist(t_history **hists, t_history *new);
void		clear_hist(t_history **hists);
t_history	*last_hist(t_history *hist);
t_history	*first_hist(t_history *hist);
t_history	*new_hist(void);

#endif
