/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:48:07 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/28 14:48:37 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * funtion to free all elements in a table of strings and also the table
 */

void	ft_free_args(char **args)
{
	int	i;

	i = 0;
	if (args != NULL)
	{
		while (args[i] != NULL)
		{
			free(args[i]);
			i++;
		}
		free(args);
		args = NULL;
	}
}
