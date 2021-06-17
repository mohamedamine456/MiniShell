/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:44:11 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/17 14:06:26 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_files.h"

int open_inputs_errors(char *str)
{
	write(2, "minishell :", 11);
	write(2, str, ft_strlen(str));
	write(2, ":", 1);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	return (-1);
}

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
			return (open_inputs_errors(inputs->file));
		tmp_fd = dup2(new_fd, 0);
		if (tmp_fd < 0)
		{
			close(new_fd);
			return (open_inputs_errors(inputs->file));
		}
		inputs = inputs->next;
	}
	close(new_fd);
	return (0);
}

