/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:03:49 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/19 16:45:42 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     main(int argc, char **argv, char **envp)
{
	char	**new_envp;

	if (argc == 1 && argv != NULL && envp != NULL)
	{
		new_envp = ft_tabdup(envp);
		write(1, "\e[1;1H\e[2J", 11);
		g_hist = init_history();
		signal_handler();
		while (TRUE)
		{
			g_hist.pos = g_hist.size;
			g_hist.wr = 0;
			g_hist.command_line = read_line(&g_hist);
			if (g_hist.command_line != NULL)
			{
				g_hist.retv = parse_execute(ft_strdup(g_hist.command_line), &new_envp, g_hist.retv);
				//if (ft_strcmp(g_hist.command_line, ""))
				//	write(1, "\n", 1);
				write_history(&g_hist, ft_strdup(g_hist.command_line));
				free(g_hist.command_line);
			}
		}
	}
}
