#include "fork_commands.h"

int		fork_commands(char *name, char **args, char **envp)
{
	char	*cmd_path;
	pid_t	pid;

	path_cmd = search_commands(name, envp);
	if (path_cmd == NULL)
		return (-1);
	pid = fork();
	if (pid == 0)
		execve(path_cmd, args, envp);
}
