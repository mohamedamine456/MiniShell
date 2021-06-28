/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:06:23 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/28 17:06:30 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int 	is_simple_cmd(t_cmd *cmd)
{
	if (cmd->args != NULL)
		return (isbuilt_in(cmd->args[0]) && (size_cmds(cmd) == 1));
	return (2);
}

int	ft_execute(t_cmd *cmd, char ***envp)
{
	int	retv;
	int	std_in;
	int	std_out;

	if (is_simple_cmd(cmd) == 1)
	{
		std_in = dup(0);
		std_out = dup(1);
		if (open_redirections(cmd->redirection) == -2)
			return (0);
		retv = exec_builtin(cmd, envp);
		dup2(std_in, 0);
		dup2(std_out, 1);
		return (retv);
	}
	return (ft_exec_nested_cmd(cmd, envp));
}
