#ifndef FORK_COMMANDS_H
# define FORK_COMMANDS_H
# include "../libft/libft.h"
# include "../parse/parse.h"
# include <sys/stat.h>

int			exec_commands(t_cmd *cmd, char	**envp);
int			fork_command(char *name, char **args, char **envp);
char		*command_path(char *cmd_name, char **envp);
char		**tab_paths(char **envp);
char		*check_right_path(char *cmd_name, char **paths);

#endif
