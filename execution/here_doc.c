/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:41:19 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/28 17:39:30 by eel-orch         ###   ########.fr       */
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
		exit(1);
}

void	close_and_exit(int fd)
{
	close(fd);
	exit(fd);
}

int	get_exit_status_and_exit(pid_t pid, int fd)
{
	int	exit_status;
	int	status;

	waitpid(pid, &status, 0);
	exit_status = get_exit_status(status);
	close(fd);
	if (exit_status == 2)
		return (1);
	return (0);
}

int	here_doc(char *delimeter, char *file_name)
{
	int		fd;
	char	*line;
	int		status;
	pid_t	pid;

	fd = open(file_name, O_RDWR | O_TRUNC | O_CREAT, S_IWUSR | S_IRUSR);
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
	return (get_exit_status_and_exit(pid, fd));
}
