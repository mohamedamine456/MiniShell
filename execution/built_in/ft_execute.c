/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:03:05 by eel-orch          #+#    #+#             */
/*   Updated: 2021/05/30 15:17:22 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int 	is_simple_cmd(t_cmd *cmd)
{
	return (isbuilt_in(cmd->name) && (size_cmds(cmd) == 1));
}

int ft_execute(t_cmd *cmd, char ***envp)
{
	if (is_simple_cmd(cmd) == 1)
		return (exec_builtin(cmd, envp));
	ft_exec_nested_cmd(cmd, envp);
	return (0);
}
