/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:27:36 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/03 18:04:32 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_option(char *str, char *name)
{
	int		i;
	char	**tab_cmds;

	i = 1;
	if (str == NULL || name == NULL || str[0] != '-')
		return (-1);
	else if (ft_strcmp(name, "echo"))
		return (-1);
	else
	{
		if (str[i] == '\0')
			return (-1);
		while (str[i] != '\0')
		{
			if (str[i] != 'n')
				return (-1);
			i++;
		}
		return (1);
	}	
}
