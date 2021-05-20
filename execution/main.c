#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
{
	int fd[2];
	char buf[3];
	pipe(fd);
	int pid = fork();
	if (pid == 0){
		close(fd[0]);
		write(fd[1], "o", 1);
		close(fd[1]);
		return (0);
	}
	wait(NULL);
	read(fd[0], buf, 3);
	printf("%s\n", buf);
	close(fd[0]);
	close(fd[1]);
}