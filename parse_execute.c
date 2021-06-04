/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:48:20 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/04 19:24:45 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_execute(char	*line, char ***envp, int retv)
{
	char	**tab_cmds;
	char	**cmd_tab;
	t_cmd	*cmd;
	int		i;

	i = 0;
	if (!ft_strcmp(line, ""))
		return (0);
	tab_cmds = split_line_commands(line);
	while (tab_cmds != NULL & tab_cmds[i] != NULL)
	{
		if (ft_strcmp(tab_cmds[i], ""))
		{
			retv = parse_execute_helper(tab_cmds[i], envp, retv);
			if (retv == 258)
			{
				ft_free_args(tab_cmds);
				return (retv);
			}
		}
		i++;
	}
	ft_free_args(tab_cmds);
	free(line);
	return (retv);
}

int	parse_execute_helper(char *tab_cmd, char ***envp, int retv)
{
	char	**cmd_tab;
	t_cmd	*cmd;
	int		val;

	cmd_tab = cut_command(tab_cmd);
	cmd_tab = replace_cmd_env(cmd_tab, *envp, retv);
	cmd_tab = clean_tab_cmd(cmd_tab);
	if (!parse_errors(cmd_tab))
	{	
		cmd = fill_command(cmd_tab);
		val = ft_execute(cmd, envp);
		ft_free_args(cmd_tab);
		clear_cmds(&cmd);
	}
	else
	{
		ft_free_args(cmd_tab);
		val = 258;
	}
	return (val);
}
