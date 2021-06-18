/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:56:10 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/18 15:27:08 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int is_redirection(char *str)
{
	int index;

	index = 0;
	if (ft_strlen(str) == 0)
		return (-1);
	if (str[0] == '<')
		return (INPUT);
	while (str[index] != '\0' && index < 2)
	{
		if (str[index] != '>')
			return (-1);
		index++;
	}
	return (index);
}

