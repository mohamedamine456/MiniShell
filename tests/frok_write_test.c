#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define CMD_NAME "bash"
#include "../../fork_commands/fork_commands.h"

int main(int argc, char **argv, char **envp)
{
	char	*path_cmd;
	int		fd;
	pid_t	pid;

	fd = open("test_fork_write.txt", O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
	pid = fork();
	if (pid == 0)
	{
		write(fd, "HELLO FROM CHILD\n", 17);
	}
	else
	{
		wait(NULL);
		write(fd, "HELLO FROM PARENT\n", 18);
		return (EXIT_SUCCESS);
	}
}
