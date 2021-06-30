/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:19:28 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/30 17:14:09 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"
#include <sys/wait.h>

int main()
{
	int fd[2];
	int i = 2;
	pid_t  pid;
	int in = 0;
	int status = 0;
	while (i > 0)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			if (i != 2)
			{
				close();
				dup2(in, 0);
				close(fd[0]);
			}
			if (i != 1)
			{
				dup2(fd[1], 1);
				close(fd[1]);
			}
			if (i == 2)
			{	
				if (execve("/bin/cat", ft_split("cat", '\0'), NULL) == -1)
					write(2, "fail1\n", 6);
			}
			else if (i == 1)
			{
				if (execve("/bin/ls", ft_split("ls", 32), NULL) == -1)
					write(2, "fail2\n", 6);
			}
			exit (0);
		}
		i--;
		in  = fd[0];
		//close(fd[1]);
		return (1);
	}
	while (waitpid(-1, &status, 0) > 0)
			continue;
	close(fd[0]);
}
