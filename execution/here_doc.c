/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:41:19 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/27 17:30:33 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ctrl_handler(int sig)
{
	exit(sig);
}

void	signals(void)
{
	if (signal(SIGINT, ctrl_handler) == SIG_ERR)
		exit(SIGINT);
}

void close_and_exit(int fd)
{
	close(fd);
	exit(fd);
}

int	here_doc(char *delimeter)
{
	int	fd;
	char *line;
	int	status;
	pid_t pid;

	fd = open("here_doc", O_RDWR | O_TRUNC | O_CREAT, S_IWUSR | S_IRUSR);
	pid = fork();
	if (pid == 0)
	{
		signals();
		while (1)
		{
			line = NULL;
			line = readline(">");
			if (line == NULL)
				close_and_exit(fd);
			if (ft_strcmp(line, delimeter) == 0)
				close_and_exit(fd);
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
			free(line);
		}
		close_and_exit(fd);
	}
	waitpid(pid, &status, 0);
	return (get_exit_status(status));
}

