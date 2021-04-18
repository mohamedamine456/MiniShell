/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:03:49 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/18 17:46:11 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     main(int argc, char **argv, char **envp)
{
	char		*command_line;
	char		ret_value;
	t_history	hist;
    
    write(1, "\e[1;1H\e[2J", 11);
	hist.fd = open_history();
	hist = read_history(hist.fd);
    if (argc == 1 && argv != NULL && envp != NULL)
    {
        while (TRUE)
        {
            write(1, "Minishell $> ", 13);
            if (get_next_line(0, &command_line) > 0)
            {
				//write_history(hist, ft_strdup(command_line));
				ret_value = parse_command(command_line, envp);	
                write(1, "\n", 1);
                free(command_line);
            }
        }
	}
}
