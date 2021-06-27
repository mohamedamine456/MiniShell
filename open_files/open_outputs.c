/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_outputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 19:50:20 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/27 18:31:15 by eel-orch         ###   ########.fr       */
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

int	open_here_doc(char *file)
{
	int fd;

	fd = here_doc(file);
	if (fd == 2)
		return (-2);
	fd = open("here_doc", O_RDONLY , S_IWUSR | S_IRUSR); 
	return (fd);
}

int	open_redirections(t_redirection *redirection)
{
	int	new_fd;
	int	tmp_fd;
	int error;
	t_redirection *tmp_redirec;

	if (redirection == NULL)
		return (0);
	tmp_redirec = redirection;
	new_fd = 0;
	error = 0;
	while (tmp_redirec != NULL)
	{
		if (tmp_redirec->type == TRUNC)
			new_fd = open(tmp_redirec->file, O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR);
		else if (tmp_redirec->type == APPEND)
			new_fd = open(tmp_redirec->file, O_WRONLY | O_CREAT | O_APPEND, S_IWUSR | S_IRUSR);
		else if (tmp_redirec->type == INPUT)
			new_fd = open(tmp_redirec->file, O_RDONLY, S_IRUSR);
		else
			new_fd = open_here_doc(tmp_redirec->file);
		if (new_fd == -2)
			return (-2);
		if (new_fd == -1)
		{
			error = open_outputs_errors(tmp_redirec->file);
			tmp_redirec = tmp_redirec->next;
			continue ;
		}
		if (tmp_redirec->type == TRUNC || tmp_redirec->type == APPEND)
			tmp_fd = dup2(new_fd, 1);
		else
			tmp_fd = dup2(new_fd, 0);
		close(new_fd);
		if (tmp_fd < 0)
			error = open_outputs_errors(tmp_redirec->file);
		tmp_redirec = tmp_redirec->next;
	}
	return (error);
}
