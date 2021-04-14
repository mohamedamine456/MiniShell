/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:44:11 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/14 14:27:15 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_files.h"

int		open_inputs(t_input *inputs, int *stdin_fd)
{
	int	new_fd;
	int	tmp_fd;

	if (inputs == NULL)
		return (0);
	*stdin_fd = dup(0);
	if (*stdin_fd < 0)
		return (-1);
	while (inputs != NULL)
	{
		new_fd = open(inputs->file, O_RDONLY, S_IRUSR);
		if (new_fd < 0)
			return (-1);
		tmp_fd = dup2(new_fd, 0);
		if (tmp_fd < 0)
		{
			close(new_fd);
			return (-1);
		}
		inputs = inputs->next;
	}
	return (0);
}
