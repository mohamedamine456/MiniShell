/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:03:49 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/22 08:03:53 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     main(int argc, char **argv, char **envp)
{
	t_history	hist;
    
    write(1, "\e[1;1H\e[2J", 11);
	hist.retv = 0;
	hist.fd = open_history();	
	hist = read_history(hist.fd);
	signal_handler();
    if (argc == 1 && argv != NULL && envp != NULL)
    {
        while (TRUE)
        {
			hist.pos = hist.size;
			hist.wr = 0;
			hist.command_line = read_line(&hist);
			write(1, "\n", 1);
			hist.retv = parse_execute(ft_strdup(hist.command_line), envp, hist.retv);
			//write(1, "\n", 1);
			//write(1, command_line, ft_strlen(command_line));
			if (ft_strcmp(hist.command_line, ""))
				write(1, "\n", 1);
			write_history(&hist, ft_strdup(hist.command_line));
			free(hist.command_line);
        }
	}
}
