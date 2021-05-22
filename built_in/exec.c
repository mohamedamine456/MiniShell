/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:03:05 by eel-orch          #+#    #+#             */
/*   Updated: 2021/04/20 17:03:06 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int 	is_simple_cmd(t_cmd *cmd)
{
	return (isbuilt_in(cmd->name) && (size_cmds(cmd) == 1));
}

int exec(t_cmd *cmd, char ***envp)
{
	if (is_simple_cmd(cmd) == 0)
		return (exec_builtin(cmd, envp));
	return (0);
	//fork that shit
}