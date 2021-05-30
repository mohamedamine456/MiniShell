/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:56:29 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/30 18:48:41 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	**split_line_commands(char *line)
{
	char		**tab;
	int			i;
	int			j;
	t_escapes	escp;

	i = 0;
	j = 0;
	escp = (t_escapes){0, 0, 0};
	tab = NULL;
	while (line[i] != '\0')
	{
		escp = ft_check_escapes(escp, line[i]);
		if (escp.s_q % 2 == 0 && escp.d_q % 2 == 0
			&& line[i] == ';' && escp.b_s == 0)
		{
			tab = ft_resize_tab(tab, ft_substr(line, j, i - j));
			j = i + 1;
		}
		if (line[i] != '\\' && escp.b_s == 1)
			escp.b_s = 0;
		i++;
	}
	tab = ft_resize_tab(tab, ft_substr(line, j, i - j));
	return (tab);
}

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
