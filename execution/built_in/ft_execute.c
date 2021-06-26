/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:03:05 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/26 15:34:38 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int 	is_simple_cmd(t_cmd *cmd)
{
	return (isbuilt_in(cmd->args[0]) && (size_cmds(cmd) == 1));
}

int ft_execute(t_cmd *cmd, char ***envp)
{
	int retv;
	int	std_in;
	int std_out;

	if (is_simple_cmd(cmd) == 1)
	{
		std_in = dup(0);
		std_out = dup(1);
		open_redirections(cmd->redirection);
		retv = exec_builtin(cmd, envp);
		dup2(std_in, 0);
		dup2(std_out, 1);
		return (retv);
	}
	return (ft_exec_nested_cmd(cmd, envp));
}
