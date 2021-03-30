/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:59:18 by mlachheb          #+#    #+#             */
/*   Updated: 2021/03/30 15:34:48 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		parse_command(char *line, char **envp)
{
	//t_cmd		*cmd;
	int			i;
	int			n_s;		//next separator
	char		*tmp_part;
	char		**tab;

	i = 0;
	n_s = 0;
	tab = NULL;
	//cmd = initialize_cmd();
	if (line == NULL)
		return (1);
	while (line[i] != '\0')
	{
		n_s = ft_next_separator(line + i);
		tmp_part = ft_substr(line, i, n_s);
		tmp_part = ft_remove_spaces(tmp_part);
		if (ft_strcmp("", tmp_part))
			tab = ft_resize_tab(tab, ft_strdup(tmp_part));
		i += n_s;
		if (ft_isseparator(line[i]))
		{
			if (!ft_isspace(line[i]))
			{
				free(tmp_part);
				tmp_part = ft_substr(line, i, 1);
				tab = ft_resize_tab(tab, ft_strdup(tmp_part));
			}
			i++;
		}
		//put_part_to_command(tmp_part, line[i], &cmd);
		free(tmp_part);
	}
	ft_print_args(tab);
	ft_free_args(tab);
	return (0);
}
