/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_in_out_files.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:21:09 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/03 14:52:45 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_files.h"

int	open_in_out_files(t_cmd *cmd, int *stdin_fd, int *stdout_fd)
{
	int		retv;

	if (cmd != NULL)
	{
		retv = open_inputs(cmd->input, stdin_fd);
		if (retv == -1)
			return (-1);
		retv = open_outputs(cmd->output, stdout_fd);
		if (retv == -1)
			return (-1);
		return (0);
	}
	return (0);
}
