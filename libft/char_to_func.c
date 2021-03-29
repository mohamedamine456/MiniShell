/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:47:21 by mlachheb          #+#    #+#             */
/*   Updated: 2021/03/28 12:52:54 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		char_to_func(char c)
{
	if (char_in_string(c, "#?*@"))
		return (0);
	if (ft_isalpha(c))
		return (1);
	if (ft_isdigit(c))
		return (2);
	return (3);
}
