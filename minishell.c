/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:03:49 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/08 19:11:53 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     main(int argc, char **argv, char **envp)
{
	char	*command_line;
	char	ret_value;
    
    write(1, "\e[1;1H\e[2J", 11);
    if (argc == 1 && argv != NULL && envp != NULL)
    {
        while (TRUE)
        {
            write(1, "Minishell $> ", 13);
            if (get_next_line(0, &command_line) > 0)
            {
				ret_value = parse_command(command_line, envp);
                //write_history(command_line);  // to write the line in a file responsible for history
                write(1, "\n", 1);
                free(command_line);
            }
        }
	}
}
