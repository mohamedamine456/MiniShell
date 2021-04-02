/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:19:55 by eel-orch          #+#    #+#             */
/*   Updated: 2021/04/02 11:20:01 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_output *new_output(void)
{
	t_output *new_output;

	new_output = (t_output *)malloc(sizeof(t_output));
	*new_output = (t_output){0, 0, 0};
	return (new_output);
}