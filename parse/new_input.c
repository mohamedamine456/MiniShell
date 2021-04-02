/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:07:59 by eel-orch          #+#    #+#             */
/*   Updated: 2021/04/02 12:08:00 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_input *new_input(void)
{
	t_input *new_input;

	new_input = (t_input *)malloc(sizeof(t_input));
	*new_input = (t_input){0, 0};
	return (new_input);
}