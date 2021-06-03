/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_outputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:25:29 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/03 15:47:27 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_files.h"

int	open_outputs(t_output *outputs)
{
	int	new_fd;
	int	tmp_fd;

	if (outputs == NULL)
		return (0);
	new_fd = 0;
	while (outputs != NULL)
	{
		if (new_fd != 0)
			close(new_fd);
		if (outputs->type == SIMPLE_REDIRECTION)
			new_fd = open(outputs->file, O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR);
		else if (outputs->type == DOUBLE_REDIRECTION)
			new_fd = open(outputs->file, O_WRONLY | O_CREAT | O_APPEND, S_IWUSR | S_IRUSR);
		if (new_fd < 0)
			return (-1);
		tmp_fd = dup2(new_fd, 1);
		if (tmp_fd < 0)
			return (-1);
		outputs = outputs->next;
	}
	close(new_fd);
	return (tmp_fd);
}
