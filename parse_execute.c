/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:48:20 by mlachheb          #+#    #+#             */
/*   Updated: 2021/07/02 12:41:31 by mlachheb         ###   ########.fr       */
/*   Updated: 2021/06/27 16:26:05 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_execute(char	*line, char ***envp, int retv)
{
	char	**cmd_tab;
	t_cmd	*cmd;

	cmd_tab = cut_command(line);
	if (!parse_errors(cmd_tab))
	{
		cmd_tab = replace_cmd_env(cmd_tab, *envp, retv);
		cmd_tab = clean_tab_cmd(cmd_tab);
		if (read_heredocs(cmd_tab))
			return (1);
		cmd = fill_command(cmd_tab);
		retv = ft_execute(cmd, envp);
		ft_free_args(cmd_tab);
		clear_cmds(&cmd);
		cmd = NULL;
	}
	else
	{
		ft_free_args(cmd_tab);
		retv = 258;
	}
	free(line);
	return (retv);
}

int	read_heredocs(char **cmd_tab)
{
	int		i;
	char	*filename;

	i = 0;
	while (cmd_tab != NULL && cmd_tab[i] != NULL)
	{
		if (!ft_strcmp(cmd_tab[i], "<<") && cmd_tab[i + 1] != NULL)
		{
			filename = ft_random_name();
			if (here_doc(cmd_tab[i + 1], filename))
			{
				free(filename);
				ft_free_args(cmd_tab);
				return (1);
			}
			free(cmd_tab[i]);
			cmd_tab[i] = ft_strdup("<");
			free(cmd_tab[i + 1]);
			cmd_tab[i + 1] = ft_strdup(filename);
			free(filename);
			filename = NULL;
		}
		i++;
	}
	return (0);
}
