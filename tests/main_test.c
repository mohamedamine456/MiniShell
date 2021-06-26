#include "../minishell.h"

int main()
{
	char *line;

	while(TRUE)
	{
		line = read_line("bash $> ");
		if (!ft_strcmp(line, "exit"))
		{
			break;
		}
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
	}
	write(1, "You exited!\n", 12);
}
