/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:22:47 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/29 20:30:17 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	dup_pipes(t_cmd *cmd, int in, int out, int i)
{
	if (cmd->next != NULL)
	{
		dup2(out, 1);
		close(out);
	}
	if (i != 0)
	{
		dup2(in, 0);
		close(in);
	}
	return (0);
}
