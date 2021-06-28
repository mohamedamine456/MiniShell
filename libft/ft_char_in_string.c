/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_in_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:45:15 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/28 14:45:31 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Test if a character is in the string
*/

int	ft_char_in_string(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}
