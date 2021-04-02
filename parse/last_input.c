/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:45:46 by eel-orch          #+#    #+#             */
/*   Updated: 2021/04/02 11:45:47 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_input *last_input(t_cmd *cmd)
{
	t_input	*tmp;

	tmp = cmd->input;
	if (tmp == NULL)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}