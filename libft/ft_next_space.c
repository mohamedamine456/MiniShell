/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:54:35 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/29 10:02:52 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function tkes a string and return the index
 * of the next space in the string
 * it does askip if the first characters are spaces
*/

int	ft_next_space(char *str)
{
	int			i;
	char		*tmp;
	t_escapes	escp;

	i = 0;
	escp = (t_escapes){0, 0, 0};
	while (str[i] != '\0')
	{
		escp = ft_check_escapes(escp, str[i]);
		if (ft_isspace(str[i]) && escp.s_q % 2 == 0
			&& escp.d_q % 2 == 0 && escp.b_s == 0)
		{
			tmp = ft_substr(str, 0, i);
			if (ft_strcmp(tmp, ""))
			{
				free(tmp);
				break ;
			}
			free(tmp);
		}
		if (str[i] != '\\' && escp.b_s == 1)
			escp.b_s = 0;
		i++;
	}
	return (i);
}
