/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:20:14 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/03 10:39:17 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	parse_errors(char **tab_cmd)
{
	int i;

	i = 0;
	while (tab_cmd != NULL && tab_cmd[i] != NULL)
	{
		if (ft_isseparator(tab_cmd[i][0]))
		{
			if (tab_cmd[i + 1] != NULL && ft_isseparator(tab_cmd[i + 1][0]))
			{
				write(1, "MiniShell: ", 11);
				write(1, "syntax error near unexpected token '", 36);
				write(1, tab_cmd[i], ft_strlen(tab_cmd[i]));
				write(1, tab_cmd[i + 1], ft_strlen(tab_cmd[i + 1]));
				write(1, "'", 1);
				return (1);
			}
		}
		i++;
	}
	return (0);
}
