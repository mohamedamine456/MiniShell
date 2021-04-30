/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:03:49 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/29 16:03:51 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     main(int argc, char **argv, char **envp)
{
	t_history	hist;

	if (argc == 1 && argv != NULL && envp != NULL)
	{
		write(1, "\e[1;1H\e[2J", 11);
		hist = init_history();
		signal_handler();
		while (TRUE)
		{
			hist.pos = hist.size;
			hist.wr = 0;
			hist.command_line = read_line(&hist);
			write(1, "\n", 1);
			if (hist.command_line != NULL)
			{
				hist.retv = parse_execute(ft_strdup(hist.command_line), &envp, hist.retv);
				if (ft_strcmp(hist.command_line, ""))
					write(1, "\n", 1);
				write_history(&hist, ft_strdup(hist.command_line));
				free(hist.command_line);
			}
		}
	}
}
