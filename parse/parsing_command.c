/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:04:10 by mlachheb          #+#    #+#             */
/*   Updated: 2021/03/29 17:07:46 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		parse_command(char *line, char **envp)
{
	t_cmd		*cmd;
	int			i;
	int			n_s;		//next separator
	char		*tmp_part;

	i = 0;
	n_s = 0;
	//cmd = initialize_cmd();
	if (line == NULL)
		return (1);
	while (str[i] != '\0')
	{
		n_s = next_separator(str + i);
		tmp_part = ft_substr(str, i, n_s);
		i += n_s;
		//put_part_to_command(tmp_part, str[i], &cmd);
		i++;
	}
}
