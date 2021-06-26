/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:41:19 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/26 21:07:08 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ctrl_handler(int sig)
{
	exit(1);
}

void	signals(void)
{
	if (signal(SIGINT, ctrl_handler) == SIG_ERR)
		exit(1);
}

int	here_doc(char *delimeter)
{
	int fd;
	char *line;
	pid_t pid;

	fd = open("here_doc", O_RDWR | O_TRUNC, S_IWUSR | S_IRUSR);
	pid = fork();
	if (pid == 0)
	{
		signals();
		while (1)
		{
			line = NULL;
			line = readline(">");
			if (line == NULL)
				exit(fd);
			if (ft_strcmp(line, delimeter) == 0)
					break;
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
			free(line);
		}
		exit(fd);
	}
	wait(NULL);
	return (fd);
}

