/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:48:20 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/20 13:40:38 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		parse_execute(char	*line, char **envp)
{
	char	**tab_cmd;
	int		retv;

	tab_cmd = cut_line(line);
	tab_cmd = replace_tab_env(tab_cmd, envp);
	tab_cmd = clean_tab_cmd(tab_cmd);
	retv = execute_commands(tab_cmd);
	ft_free_args(tab_cmd);
	return (retv);
}

int		execute_commands(char **tab_cmd)
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
			ft_print_args(one_cmd);
			write(1, "\n", 1);
			ft_free_args(one_cmd);
			one_cmd = NULL;
		}
		i++;
	}
	if (one_cmd != NULL)
	{
		cmd = fill_command(one_cmd);
		ft_print_args(one_cmd);
		ft_free_args(one_cmd);
	}
	return (1);
}
