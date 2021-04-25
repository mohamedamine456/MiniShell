/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:46:54 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/25 13:30:58 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int check_line_errors(char *line)
{
	int i;
	t_escapes escp;

	i = 0;
	escp = (t_escapes){0, 0, 0};
	while (line != NULL && line[i] != '\0')
	{
		escp = ft_check_escapes(escp, line[i]);
		if (line[i] != '\\' && escp.b_s == 1)
			escp.b_s = 0;
		i++;
	}
	if (escp.b_s == 1 || escp.s_q % 2 != 0 || escp.d_q % 2 != 0)
		return (-1);
	return (0);
}
