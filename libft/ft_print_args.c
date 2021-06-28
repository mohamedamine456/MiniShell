/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:59:55 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/28 15:00:09 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_args(char **args)
{
	int	i;

	i = 0;
	while (args != NULL && args[i] != NULL)
	{
		write(1, "{", 1);
		write(1, args[i], ft_strlen(args[i]));
		write(1, "}", 1);
		i++;
	}
}
