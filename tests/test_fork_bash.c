#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define CMD_NAME "bash"
#include "../fork_commands/fork_commands.h"


void handler(int sig)
{
	if (sig == 2)
	{
		write(1, "quit\n", 7);
	}
	else if (sig == 3)
	{
		write(1, "SIGQUIT\n", 8);
	}
}

int main(int argc, char **argv, char **envp)
{
	char	*path_cmd;
	pid_t	pid;
	char	**tab;

	if (signal(SIGINT, handler) == SIG_ERR)
	{
		write(1, "SIGINT ERROR\n", 13);
		exit(1);
	}
	if (signal(SIGQUIT, handler) == SIG_ERR)
	{
		write(1, "SIGQUIT ERROR\n", 14);
		exit(1);
	}
	tab = NULL;
	tab = ft_resize_tab(tab, ft_strdup(""));
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
			execve(path_cmd, tab, envp);
			perror("execve:");
		}
		else
		{
			wait(NULL);
			write(1, "all good from parent", 20);
			exit(0);
		}
	}
	else
	{
		write(1, "not perfect commad.\n", 20);
		exit(0);
	}
}
