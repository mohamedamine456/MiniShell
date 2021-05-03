/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:48:20 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/03 13:26:16 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		parse_execute(char	*line, char ***envp, int retv)
{
	char	**tab_cmd;

	line = trim_replace(line, *envp, retv);
	tab_cmd = cut_line(line);
	tab_cmd = clean_tab_cmd(tab_cmd);
	if (!parse_errors(tab_cmd))
		retv = split_commands(tab_cmd, envp, retv);
	ft_free_args(tab_cmd);
	free(line);
	return (retv);
}

int		split_commands(char **tab_cmd, char ***envp, int retv)
{
	t_cmd   *cmd;
	char    **one_cmd;
	int     i;

	i = 0;
	one_cmd = NULL;
	while (tab_cmd != NULL && tab_cmd[i] != NULL)
	{
		if (ft_strcmp(tab_cmd[i], ";"))
			one_cmd = ft_resize_tab(one_cmd, ft_strdup(tab_cmd[i]));
		else if (one_cmd != NULL)
		{
			//cmd = fill_command(one_cmd);
			//execute command
			//print_cmds(cmd);
			ft_print_args(one_cmd);
			ft_free_args(one_cmd);
			one_cmd = NULL;
		}
		i++;
	}
	if (one_cmd != NULL)
	{
		//cmd = fill_command(one_cmd);
		//print_cmds(cmd);
		ft_print_args(one_cmd);
		ft_free_args(one_cmd);
	}
	return (retv);
}
