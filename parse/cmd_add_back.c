/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:32:21 by eel-orch          #+#    #+#             */
/*   Updated: 2021/03/30 16:48:15 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void cmd_add_back(t_cmd **cmd, t_cmd *new)
{
	t_cmd *tmp;

	tmp = *cmd;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
