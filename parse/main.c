/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:40:42 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/22 11:59:30 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#define DELIMITER "word"
int main(int argc, char *argv[])
{
	char *path = "/bin/cat";
	char **args = ft_split("-", '\0');
	pid_t pid;
	char *line = NULL;
	int fd;
	int std_in = dup(0);
	pid = fork();
	if (pid == 0)
	{
		fd = open("/tmp/here_document", O_RDONLY, S_IRUSR);
		while (strcmp(line, DELIMITER) != 0)
		{
			line = readline(">");
			write(fd, line, strlen(line));
			write(fd, "\n", 1);
			free(line);
			line = NULL;
		}
		dup2(fd, 0);
		close(fd);
		execve(path, args, NULL);
		return (0);
	}
	wait(NULL);
}

