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
# include "parse_structs.h"
# include "cmd.h"

int			parse_command(char *line, char **envp);


char		**clean_tab_cmd(char **tab_cmd);
char		*clean_str(char *str);

int			check_by_options(char *str, char *options);
char		*name_to_option(char *name);
int			is_option(char *str, char *name);

char		**replace_tab_env(char **tab_cmd, char **envp);
char		*replace_str(char *str, char **envp);
char		*trim_replace(char *str, char **envp);

t_cmd		*new_cmd(t_cmd cmd);
void		print_cmd(t_cmd cmd);
void		cmd_add_back(t_cmd **cmd, t_cmd *new);
#endif
