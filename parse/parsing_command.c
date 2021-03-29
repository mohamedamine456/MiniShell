/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:04:10 by mlachheb          #+#    #+#             */
/*   Updated: 2021/03/29 15:37:48 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		parse_command(char *line, char **envp)
{
	int			i;
	t_escapes	escp;

	i = 0;
	escp = (t_escape){0, 0, 0};
	if (line == NULL)
		return (1);
	while (str[i] != '\0')
	{

	}
}
