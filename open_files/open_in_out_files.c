/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_in_out_files.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:21:09 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/03 12:48:58 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_files.h"

int	open_in_out_files(t_cmd *cmd)
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
