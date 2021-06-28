/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_separator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:15:37 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/28 14:54:03 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_next_separator(char *str)
{
	int			i;
	t_escapes	escp;

	i = 0;
	escp = (t_escapes){0, 0, 0};
	while (str[i] != '\0')
	{
		escp = ft_check_escapes(escp, str[i]);
		if (ft_isseparator(str[i]) && escp.s_q % 2 == 0
			&& escp.d_q % 2 == 0 && escp.b_s == 0)
		{
			break ;
		}
		if (str[i] != '\\' && escp.b_s == 1)
			escp.b_s = 0;
		i++;
	}
	return (i);
}
