/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:44:11 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/08 15:10:34 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_files.h"

int		open_inputs(t_input *inputs)
{
	int	new_fd;
	int	tmp_fd;
	int stdin_fd;

	old_fd = 0;
	stdin_fd = dup(0);
	if (stdin_fd == -1)
		return (-1);
	while (inputs != NULL)
	{
		new_fd = open(inputs->file, O_RDONLY, S_IRUSR);
		if (new_fd == -1)
			return (-1);
		tmp_fd = dup2(0, new_fd);
		if (tmp_fd == -1)
		{
			close(new_fd);
			return (-1);
		}
		inputs = inputs->next;
	}
}
