/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:22:47 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/30 19:02:25 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	dup_pipes(t_cmd *cmd, int in, int out, int i, int *fd)
{
	if (cmd->next != NULL)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
	}
	if (i != 0)
	{
		dup2(in, 0);
		close(fd[1]);
		close(fd[0]);
	}
	return (0);
}
