/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:36:13 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/28 13:51:37 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs_functions.h"

void	add_redirection_back(t_redirection **redirection, t_redirection *new)
{
	t_redirection	*tmp;

	if (*redirection == NULL)
		*redirection = new;
	else
	{
		tmp = *redirection;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	clear_redirection(t_redirection **redi)
{
	t_redirection	*tmp;

	tmp = *redi;
	if (redi == NULL)
		return ;
	while (*redi)
	{
		tmp = *redi;
		*redi = (*redi)->next;
		if (tmp->file != NULL)
			free(tmp->file);
		free(tmp);
	}
}

void	clear_inputs(t_input **inputs)
{
	t_input	*input1;
	t_input	*input2;

	input1 = *inputs;
	while (input1 != NULL)
	{
		input2 = input1->next;
		if (input1->file != NULL)
			free(input1->file);
		free(input1);
		input1 = NULL;
		input1 = input2;
	}
	inputs = NULL;
}

t_redirection	*new_redirection(void)
{
	t_redirection	*redirection;

	redirection = (t_redirection *)malloc(sizeof(t_redirection));
	redirection->type = -1;
	redirection->file = NULL;
	redirection->next = NULL;
	return (redirection);
}
