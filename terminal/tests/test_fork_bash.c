#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define CMD_NAME "bash"
#include "../../fork_commands/fork_commands.h"

int main(int argc, char **argv, char **envp)
{
	char	*path_cmd;
	pid_t	pid;

	if (argc != 2)
	{
		write(1, "Error arguments.\n", 17);
		exit(1);
	}
	path_cmd = command_path(argv[1], envp);
	if (path_cmd != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(path_cmd, NULL, envp);
		}
		else
		{
			wait(NULL);
			write(1, "all good from parent", 8);
			exit(0);
		}
	}
	else
	{
		write(1, "not perfect commad.\n", 20);
		exit(0);
	}
}
