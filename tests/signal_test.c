#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handler(int sig)
{
	if (sig == 2)
	{
		kill(0, sig);
		//write(1, "SIGINT\n", 7);
	}
	else if (sig == 3)
	{
		kill(0, sig);
		//write(1, "SIGQUIT\n", 8);
	}
}

int main()
{
	pid_t	pid;
	int		i;

	i = 0;
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
	pid  = fork();
	if (pid == 0)
	{
		while (++i < 11)
		{
			printf("hello\n");
			sleep(2);
		}
	}
	else
	{
		wait(NULL);
		while (1)
		{
			write(1, "hello\n", 6);
			sleep(2);
		}
	}
}
