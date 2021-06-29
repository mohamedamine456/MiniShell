/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_std_in_out.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:27:46 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/29 20:28:13 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	redirect_std_in_out(t_cmd *cmd, int cmd_index, int in, int *fd)
{
	int	error;

	error = 0;
	error = dup_pipes(cmd, in, fd[1], cmd_index);
	error = open_redirections(cmd->redirection);
	if (error < 0)
		exit (1);
}
