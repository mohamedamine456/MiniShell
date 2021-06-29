/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isbuilt_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:30:21 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/29 20:15:59 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	tolow(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] >= 'A' && str[index] <= 'Z')
			str[index] = str[index] + 32;
		index++;
	}
}

int	isbuilt_in(char *str)
{
	int		i;

	if (ft_strcmp(str, "echo") == 0)
		return (B_ECHO);
	else if (ft_strcmp(str, "export") == 0)
		return (B_EXPORT);
	else if (ft_strcmp(str, "env") == 0)
		return (B_ENV);
	else if (ft_strcmp(str, "exit") == 0)
		return (B_EXIT);
	else if (ft_strcmp(str, "cd") == 0)
		return (B_CD);
	else if (ft_strcmp(str, "unset") == 0)
		return (B_UNSET);
	else if (ft_strcmp(str, "pwd") == 0)
		return (B_PWD);
	return (0);
}
