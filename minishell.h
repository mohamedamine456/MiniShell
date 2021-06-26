/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:47:36 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/26 20:40:41 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define TRUE 1
# define _POSIX_SOURCE
# include <unistd.h>
# undef _POSIX_SOURCE
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "get_next_line/get_next_line.h"
# include "parse/parse.h"
# include "terminal/terminal.h"
# include "execution/execution.h"
# include "execution/built_in/built_in.h"
# include "fork_commands/fork_commands.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "open_files/open_files.h"
# include "structs.h"
#include <readline/readline.h>
#include <readline/history.h>

int				open_history(void);
void			write_hist(t_general_data *hist, char *line);
t_general_data	init_general_data(void);
t_history		*read_hists(int fd);

/*
 * prototypes for parse_execute.c file
 */

int				parse_execute(char *line, char ***envp, int retv);
int				parse_execute_helper(char *tab_cmd, char ***envp, int *retv);

/*
 * prototypes for hist_functions.c file
 */

void			add_back_hist(t_history **hists, t_history *new);
void			clear_hist(t_history **hists);
t_history		*last_hist(t_history *hist);
t_history		*first_hist(t_history *hist);
t_history		*new_hist(void);

#endif
