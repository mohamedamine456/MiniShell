#ifndef SEARCH_COMMANDS_H
# define SEARCH_COMMANDS_H
# include "../libft/libft.h"
# include <sys/stat.h>

char		*command_path(char *cmd_name, char **envp);
char		**tab_paths(char **envp);
char		*check_right_path(char *cmd_name, char **paths);

#endif
