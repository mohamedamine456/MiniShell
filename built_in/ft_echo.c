# include "built_in.h"

int		ft_echo(char **args, char *option)
{
	int i;

	i = 0;
	while (args != NULL && args[i] != NULL)
		write(1, args[i], ft_strlen(args[i]));
	if (option != NULL)
		write(1, "\n", 1);
}
