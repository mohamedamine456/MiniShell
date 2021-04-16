#include "fork_commands.h"

int		exec_commands(t_cmd *cmd, char	**envp)
{
	t_cmd *tmp_cmd;

	cmd_tmp = cmd;
	while (tmp_cmd != NULL)
	{
		//fork and pipe
		tmp_cmd = tmp_cmd->next;
	}
}

int		fork_command(char *name, char **args, char **envp)
{
	char	*cmd_path;
	pid_t	pid;

	path_cmd = search_commands(name, envp);
	if (path_cmd == NULL)
		return (-1);
	pid = fork();
	if (pid == 0)
		execve(path_cmd, args, envp);
	else
		wait(NULL);
}
