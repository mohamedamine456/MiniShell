/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:27:36 by eel-orch          #+#    #+#             */
/*   Updated: 2021/04/10 11:36:55 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parse.h"

int		check_by_options(char *str, char *options)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_char_in_string(str[i], options))
			return (0);
		i++;
	}
	return (1);
}

char	*name_to_option(char *name)
{
	if (!ft_strcmp(name, "echo"))
		return (ECHO_OPTIONS);
	else if (!ft_strcmp(name, "pwd"))
		return (PWD_OPTIONS);
	else if (!ft_strcmp(name, "env"))
		return (ENV_OPTIONS);
	else if (!ft_strcmp(name, "cd"))
		return (CD_OPTIONS);
	else if (!ft_strcmp(name, "export"))
		return (EXPORT_OPTIONS);
	else
		return (UNSET_OPTIONS);

}

int		is_option(char *str, char *name)
{
	int		i;
	char	**tab_cmds;

	i = 1;
	if (str == NULL || name == NULL || str[0] != '-')
		return (-1);
	tab_cmds = ft_split(COMMANDS, ' ');
	if (!ft_str_in_args(name, tab_cmds))
	{
		ft_free_args(tab_cmds);
		return (-1);
	}
	else if (!check_by_options(str + 1, name_to_option(name)))
		return (-1);
	return (1);
}
