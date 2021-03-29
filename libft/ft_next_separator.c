/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_separator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:15:37 by mlachheb          #+#    #+#             */
/*   Updated: 2021/03/29 17:07:52 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_next_separator(char *str)
{
	int			i;
	char		*tmp;
	t_escapes	escp;

	i = 0;
	tmp = NULL;
	escp = (t_escapes){0, 0, 0};
	while (str[i] != '\0')
	{
		escp = ft_check_escapes(escp, str[i]);
		if (ft_isseparator(str[i]) && escp.s_q % 2 == 0
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
