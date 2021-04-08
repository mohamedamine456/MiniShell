/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:44:11 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/08 11:21:52 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_files.h"

int		open_inputs(t_input *inputs)
{
	int	old_fd;
	int	new_fd;

	old_fd = 0;
	while (inputs != NULL)
	{
		new_fd = open(inputs->file, O_RDONLY, S_IRUSR);
		if (new_fd == -1)
			return (-1);
		tmp_fd = dup(new_fd);
		if (tmp_fd == -1 && errno != EBADF)
			return (-1);
		else
		{
		}
	}
}
