/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:47:21 by mlachheb          #+#    #+#             */
/*   Updated: 2021/03/29 15:28:17 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_char_to_func(char c)
{
	if (ft_char_in_string(c, "#?*@"))
		return (0);
	if (ft_isalpha(c))
		return (1);
	if (ft_isdigit(c))
		return (2);
	return (3);
}
