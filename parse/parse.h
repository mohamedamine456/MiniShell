#ifndef PARSE_H
# define PARSE_H
# define SEPARATORS " \t\v\b><|;"
# define DLR_SPECIALS "#?*@"
# define ECHO_OPTIONS "neE"
# define PWD_OPTIONS "LP"
# define ENV_OPTIONS "iPSuv"
# define CD_OPTIONS "LPe@"
# define EXPORT_OPTIONS "fnp"
# define UNSET_OPTIONS "fvn"
# define COMMANDS "echo cd pwd export unset env exit"
# include "../libft/libft.h"
# include "cmd.h"
# include "structs_functions/structs_functions.h"

int			parse_command(char *line, char **envp);
int			separate_command(char **tab_cmd);
char        **cut_line(char *line);
char        *cut_separator(char *line, int *i);


char		**clean_tab_cmd(char **tab_cmd);
char		*clean_str(char *str);

int			check_by_options(char *str, char *options);
char		*name_to_option(char *name);
int			is_option(char *str, char *name);

char		**replace_tab_env(char **tab_cmd, char **envp);
char		*trim_replace(char *str, char **envp);
char		*search_env(char *str, char **envp);
char        *replace_env(char *str, char **envp, int *i);
char        *replace_return(char *str, int *i);

char		*rep_spec(char *str, char **envp, int *i);
char		*rep_alpha(char *str, char **envp, int *i);
char		*rep_digit(char *str, char **envp, int *i);

void		print_cmd(t_cmd cmd);

t_cmd		*fill_command(char **tab);
void		add_cmd_options(char **old_option, char *new);
int			is_option(char *str, char *name);

#endif
