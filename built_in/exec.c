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

#include "built_in.h"

int	is_simple_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	tmp = cmd;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i && isbuilt_in(cmd->name));
}

int exec(t_cmd *cmd, char ***envp)
{
	if (is_simple_cmd(cmd) == 0)
		return (exec_builtin(cmd, envp));
	return (0);
	//fork that shit
}