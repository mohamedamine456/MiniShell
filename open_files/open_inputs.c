/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:44:11 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/03 17:45:05 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_files.h"

int	open_inputs(t_input *inputs)
{
	int	new_fd;
	int	tmp_fd;

	if (inputs == NULL)
		return (0);
	new_fd = 0;
	while (inputs != NULL)
	{
		if (new_fd != 0)
			close(new_fd);
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
	close(new_fd);
	return (0);
}
