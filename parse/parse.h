/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:45:15 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/28 13:46:12 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "../libft/libft.h"
# include "cmd.h"
# include "structs_functions/structs_functions.h"

/*
 * parse_command.c prototypes
 */
char		**split_line_commands(char *line);
char		**cut_command(char *command);
char		*cut_separator(char *command, int *i);

/*
 * clean_tab_cmd.c prototypes
 */

char		**clean_tab_cmd(char **tab_cmd);
char		*clean_str_helper(char *str, char *new, t_clean *cl);
char		*clean_str(char *str);

/*
 * check_option.c prototypes
 */

int			is_option(char *str, char *name);

/*
 * replace_env.c prototypes
 */
char		**replace_cmd_env(char **tab_cmd, char **envp, int retv);
char		*trim_replace(char *str, char **envp, int retv);
char		*trim_replace_helper(char *str, t_repenv repen,
				char **envp, int retv);
char		*replace_env(char *str, char **envp, int *i);
char		*replace_num(char *str, int *i);
char		*replace_return(char *str, int *i, int retv);

void		print_cmd(t_cmd *cmd);

/*
 * fill_command.c prototypes
 */

t_cmd		*fill_command(char **tab);
void		add_cmd_options(char **old_option, char *new);
int			is_redirection(char *str);

/*
 * parse_errors.c prototypes
 */

int			parse_errors(char **tab_cmd);
int			check_redirections(char *redir);
int			print_parse_errors(char *error, char *error_plus);

#endif
