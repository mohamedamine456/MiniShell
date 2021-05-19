/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:20:14 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/19 16:37:32 by mlachheb         ###   ########.fr       */
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
			if (tab_cmd[i + 1] != NULL)
			{
				if (ft_isseparator(tab_cmd[i + 1][0]))
					return (print_parse_errors(tab_cmd[i], tab_cmd[i + 1]));
			}
			else
			{
				if (tab_cmd[i][0] != ';')
					return (print_parse_errors(tab_cmd[i], ""));
			}
		}
		i++;
	}
	return (0);
}

int	print_parse_errors(char *error, char *error_plus)
{
	write(1, "MiniShell: ", 11);
	write(1, "syntax error near unexpected token '", 36);
	write(1, error, ft_strlen(error));
	write(1, error_plus, ft_strlen(error_plus));
	write(1, "'\n", 2);
	return (1);
}
