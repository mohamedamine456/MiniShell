/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:03:49 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/26 20:11:10 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	**new_envp;

	if (argc == 1 && argv != NULL && envp != NULL)
	{
		new_envp = ft_dup_env(envp);
		write(1, "\e[1;1H\e[2J", 11);
		g_data = init_general_data();
		signal_handler();
		while (TRUE)
		{
			g_data.command_line = read_line("MiniShell %> ");
			if (g_data.command_line != NULL)
			{
				g_data.retv = parse_execute(ft_strdup(g_data.command_line),
						&new_envp, g_data.retv);
				write_hist(&g_data, ft_strdup(g_data.command_line));
				free(g_data.command_line);
			}
		}
	}
	return (0);
}
