/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:32:24 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/17 14:30:04 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

char	*just_read(void)
{
	char	*buff;
	char	*tmp;
	t_flags	fl;

	fl = (t_flags){0, 0, 0};
	buff = ft_strdup("");
	tmp = malloc(2);
	while (TRUE)
	{
		if (read(0, tmp, 1) > 0)
		{
			tmp[1] = '\0';
			if (tmp[0] == '\n')
				break ;
			buff = add_buffer(buff, tmp, &fl);
		}
		else
			break ;
	}
	free(tmp);
	return (buff);
}

char	*add_buffer(char *buff, char *tmp, t_flags *fl)
{
	if (tmp[0] == '\x7f')
	{
		delete_char(&buff);
		return (buff);
	}
	if (!check_flags(tmp[0], fl))
	{
		buff = ft_strjoin(buff, tmp);
		return (buff);
	}
	else
	{
		//apply_flags(&buff, tmp, fl);
		return (buff);
	}
}
