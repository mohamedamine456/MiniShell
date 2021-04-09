# include "built_in.h"

void	ft_echo(char **args, char *option, int *retv)
{
	int i;

	i = 0;
	while (args != NULL && args[i] != NULL)
		write(1, args[i], ft_strlen(args[i]));
	if (option != NULL)
		write(1, "\n", 1);
	if (errno == 0)
		*retv = 0;
	else
		*retv == 1;
}
