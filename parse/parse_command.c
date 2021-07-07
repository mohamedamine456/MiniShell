/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:56:29 by mlachheb          #+#    #+#             */
/*   Updated: 2021/07/01 12:02:47 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	**cut_command(char *command)
{
	int			i;
	int			n_s;
	char		*tmp_part;
	char		**tab;

	i = 0;
	n_s = 0;
	tab = NULL;
	if (command == NULL)
		return (NULL);
	while (command[i] != '\0')
	{
		n_s = ft_next_separator(command + i);
		tmp_part = ft_substr(command, i, n_s);
		tmp_part = ft_remove_spaces(tmp_part);
		if (ft_strcmp("", tmp_part))
			tab = ft_resize_tab(tab, ft_strdup(tmp_part));
		i += n_s;
		free(tmp_part);
		tmp_part = cut_separator(command, &i);
		if (tmp_part != NULL)
			tab = ft_resize_tab(tab, ft_strdup(tmp_part));
		free(tmp_part);
	}
	return (tab);
}

char	*cut_separator(char *command, int *i)
{
	char	*tmp_part;
	char	c;
	int		j;

	j = 0;
	tmp_part = NULL;
	if (ft_isseparator(command[*i]))
	{
		if (ft_isspace(command[*i]))
			(*i)++;
		else
		{
			if (command[*i] == '>' || command[*i] == '<')
			{
				c = command[*i];
				while (command[*i + j] == c)
					j++;
				tmp_part = ft_substr(command, *i, j);
				*i += j;
			}
			else
				tmp_part = ft_substr(command, (*i)++, 1);
		}
	}
	return (tmp_part);
}
