/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:41:19 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/26 18:46:13 by eel-orch         ###   ########.fr       */
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

int main()
{
	int fd = open("here_doc", O_RDWR | O_TRUNC, S_IWUSR | S_IRUSR);
	char *line = NULL;
	pid_t pid;
	int is_allocated = 1;
	pid = 0;
	//pid = fork();
	if (pid == 0)
	{
		write(1, "d", 1);
		while (1)
		{
			line = NULL;
			line = readline(">");
			if (line == NULL)
			{
				rl_replace_line();
				line = "";
				is_allocated = 0;
			}
			if (strcmp(line, DELIMITER) == 0)
				break;
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
			if (is_allocated != 0)
				free(line);
			exit(0);
		}
	}
//	else
//	{
//		wait(NULL);
//		write(1, "2", 1);
//	}
}
