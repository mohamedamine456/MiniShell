/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:01:49 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/18 20:23:28 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs_functions.h"

void	add_back_cmd(t_cmd **cmds, t_cmd *new)
{
	t_cmd	*cmd;

	cmd = *cmds;
	if (cmd == NULL)
		*cmds = new;
	else
	{
		cmd = last_cmd(*cmds);
		cmd->next = new;
	}
}

void	clear_cmds(t_cmd **cmds)
{
	t_cmd	*cmd1;
	t_cmd	*cmd2;

	cmd1 = *cmds;
	while (cmd1 != NULL)
	{
		cmd2 = cmd1->next;
		if (cmd1->name != NULL)
			free(cmd1->name);
		if (cmd1->option != NULL)
			free(cmd1->option);
		if (cmd1->args != NULL)
			ft_free_args(cmd1->args);
		if (cmd1->redirection != NULL)
			clear_redirection(&(cmd1->redirection));		
		free(cmd1);
		cmd1 = NULL;
		cmd1 = cmd2;
	}
	cmds = NULL;
}

t_cmd	*last_cmd(t_cmd *cmd)
{
	if (cmd != NULL)
	{
		while (cmd->next != NULL)
			cmd = cmd->next;
	}
	return (cmd);
}

t_cmd	*new_cmd(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->name = NULL;
	cmd->option = NULL;
	cmd->args = NULL;
	cmd->redirection = NULL;
	cmd->next = NULL;
	return (cmd);
}

int	size_cmds(t_cmd *cmds)
{
	int	i;

	i = 0;
	while (cmds != NULL)
	{
		i++;
		cmds = cmds->next;
	}
	return (i);
}
