/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:13:15 by eel-orch          #+#    #+#             */
/*   Updated: 2021/03/30 16:42:45 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_cmd *new_cmd(void)
{
	t_cmd *new_cmd;

	new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	new_cmd->option = NULL;
	new_cmd->name = NULL;
	new_cmd->args = NULL;
	new_cmd->input = NULL;
	new_cmd->output = NULL;
	new_cmd->next = NULL;
	return (new_cmd);
}