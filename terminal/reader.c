/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:32:24 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/18 15:15:37 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

char	*just_read(void)
{
	char	*line;
	char	*tmp;
	t_flags	fl;

	fl = (t_flags){0, 0, 0};
	line = ft_strdup("");
	tmp = malloc(2);
	while (TRUE)
	{
		if (read(0, tmp, 1) > 0)
		{
			tmp[1] = '\0';
			if (tmp[0] == '\n')
				break ;
			line = add_buffer(line, tmp, &fl);
		}
		else
			break ;
	}
	free(tmp);
	return (line);
}

char	*add_buffer(char *line, char *tmp, t_flags *fl)
{
	if (tmp[0] == 4)
	{
		if (!ft_strcmp(line, ""))
		{
			free(line);
			exit(0);
		}
		return (line);
	}
	else if (tmp[0] == 127)
	{	
		delete_char(&line);
		return (line);
	}
	else if (!check_flags(tmp[0], fl))
	{
		write(1, tmp, 1);
		line = ft_strjoin(line, tmp);
		return (line);
	}
	else
	{
		//apply_flags(&line, tmp, fl);
		return (line);
	}
}
