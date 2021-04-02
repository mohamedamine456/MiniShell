/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:14:02 by eel-orch          #+#    #+#             */
/*   Updated: 2021/04/02 11:14:04 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_output *last_output(t_cmd *cmd)
{
	t_cmd		*last_cmd;
	t_output	*tmp;

	last_cmd = cmd_last(cmd);
	tmp = last_cmd->output;
	while (tmp)
		tmp = tmp->next;
	return (tmp);
}