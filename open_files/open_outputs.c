/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_outputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:25:29 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/14 14:27:46 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_files.h"

int		open_outputs(t_output *outputs, int *stdout_fd)
{
	int	new_fd;
	int	tmp_fd;

	if (outputs == NULL)
		return (0);
	*stdout_fd = dup(1);
	if (*stdout_fd < 0)
		return (-1);
	while (outputs != NULL)
	{
		if (outputs->type == SIMPLE_REDIRECTION)
			new_fd = open(outputs->file, O_WRONLY, S_IWUSR);
		else if (outputs->type == DOUBLE_REDIRECTION)
			new_fd = open(outputs->file, O_WRONLY | O_APPEND, S_IWUSR);
		if (new_fd < 0)
			return (-1);
		tmp_fd = dup2(new_fd, 1);
		if (tmp_fd < 0)
		{
			close(new_fd);
			return (-1);
		}
		outputs = outputs->next;
	}
	return (0);
}
