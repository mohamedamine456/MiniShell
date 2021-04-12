#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define CMD_NAME "bash"
#include "../../search_commands/search_commands.h"

int main(int argc, char **argv, char **envp)
{
	char	*path_cmd;
	pid_t	pid;

	if (argc != 2)
	{
		write(1, "Error arguments.\n", 17);
		exit(1);
	}
	if (!ft_strcmp(argv[1], "bash"))
	{
		pid = fork();
		if (pid == 0)
		{
			path_cmd = command_path(CMD_NAME, envp);
			if (path_cmd == NULL)
			{
				write(1, "command not found.\n", 19);
				exit(1);
			}
			execve(path_cmd, NULL, envp);
			perror("execve");
		}
		else
		{
			wait(NULL);
			write(1, "all good", 8);
			exit(0);
		}
	}
	else
	{
		write(1, "not perfect commad.\n", 20);
		exit(0);
	}
}
