/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:44:11 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/08 12:22:02 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_files.h"

int		open_inputs(t_input *inputs)
{
	int	old_fd;
	int	new_fd;
	int	tmp_fd;

	old_fd = 0;
	tmp_fd = dup(0);
	if (tmp_fd == -1 && errno != EBADF)
		return (-1);
}
