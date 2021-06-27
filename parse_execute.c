/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:48:20 by mlachheb          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/06/27 17:03:09 by eel-orch         ###   ########.fr       */
=======
/*   Updated: 2021/06/27 16:26:05 by mlachheb         ###   ########.fr       */
>>>>>>> 5e7f9549798bad8447692ed31a91b0070c5e2338
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_execute(char	*line, char ***envp, int retv)
{
	char	**tab_cmds;
	char	**cmd_tab;
	t_cmd	*cmd;

	cmd_tab = cut_command(line);
	cmd_tab = replace_cmd_env(cmd_tab, *envp, retv);
	cmd_tab = clean_tab_cmd(cmd_tab);
	if (!parse_errors(cmd_tab))
	{	
		cmd = fill_command(cmd_tab);
		sleep(10);
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

//int	parse_execute_helper(char *tab_cmd, char ***envp, int *retv)
//{
//	char	**cmd_tab;
//	t_cmd	*cmd;
//
//	cmd_tab = cut_command(tab_cmd);
//	cmd_tab = replace_cmd_env(cmd_tab, *envp, *retv);
//	cmd_tab = clean_tab_cmd(cmd_tab);
//	if (!parse_errors(cmd_tab))
//	{	
//		cmd = fill_command(cmd_tab);
//		*retv = ft_execute(cmd, envp);
//		ft_free_args(cmd_tab);
//		clear_cmds(&cmd);
//		cmd = NULL;
//	}
//	else
//	{
//		ft_free_args(cmd_tab);
//		*retv = 258;
//	}
//	return (*retv);
//}
