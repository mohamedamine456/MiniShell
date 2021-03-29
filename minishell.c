#include "minishell.h"

int     main(int argc, char **argv, char **envp)
{
	char	*command_line;
    t_commands  *commands;
    
    commands = NULL;
    write(1, "\e[1;1H\e[2J", 11);
    if (argc == 1 && argv != NULL && envp != NULL)
    {
        while (TRUE)
        {
            write(1, "Minishell $> ", 13);
            if (get_next_line(0, &command_line) > 0)
            {
                commands = parse_command(command_line, commands, envp);
                //write_history(command_line);  // to write the line in a file responsible for history
                write(1, "\n", 1);
                free(command_line);
                command_line = NULL;
            }
        }

