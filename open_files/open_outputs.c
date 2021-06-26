/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_outputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 19:50:20 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/26 21:07:51 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_files.h"

int open_outputs_errors(char *str)
{
	write(2, "minishell :", 11);
	write(2, str, ft_strlen(str));
	write(2, ":", 1);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	return (-1);
}

int	open_redirections(t_redirection *redirection)
{
	int	new_fd;
	int	tmp_fd;
	int error;

	if (redirection == NULL)
		return (0);
	new_fd = 0;
	error = 0;
	while (redirection != NULL)
	{
		if (redirection->type == TRUNC)
			new_fd = open(redirection->file, O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR);
		else if (redirection->type == APPEND)
			new_fd = open(redirection->file, O_WRONLY | O_CREAT | O_APPEND, S_IWUSR | S_IRUSR);
		else if (redirection->type == INPUT)
			new_fd = open(redirection->file, O_RDONLY, S_IRUSR);
		else
			new_fd = here_doc(redirection->file);
		if (new_fd == -1)
		{
			error = open_outputs_errors(redirection->file);
			redirection = redirection->next;
			continue ;
		}
		if (redirection->type == TRUNC || redirection->type == APPEND)
			tmp_fd = dup2(new_fd, 1);
		else
			tmp_fd = dup2(new_fd, 0);
		close(new_fd);
		if (tmp_fd < 0)
			error = open_outputs_errors(redirection->file);
		redirection = redirection->next;
	}
	close(new_fd);
	return (error);
}
