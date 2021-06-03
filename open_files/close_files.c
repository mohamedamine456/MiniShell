/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:11:24 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/03 19:22:58 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_files.h"

int	close_files(int stdin_fd, int stdout_fd)
{
	if (dup2(0, stdin_fd) < 0)
		return (-1);
	if (close(stdin_fd) < 0)
		return (-1);
	if (dup2(1, stdout_fd) < 0)
		return (-1);
	if (close(stdout_fd) < 0)
		return (-1);
	return (0);
}
