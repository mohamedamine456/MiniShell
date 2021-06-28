/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_in_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:53:56 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/28 15:54:05 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_in_args(char *str, char **args)
{
	int	i;

	i = 0;
	if (str == NULL || args == NULL)
		return (0);
	while (args[i] != NULL)
	{
		if (!ft_strcmp(str, args[i]))
			return (1);
		i++;
	}
	return (0);
}
