# include "built_in.h"

void	ft_echo(t_builtin_vars var, int *retv)
{
	int i;

	i = 0;
	while (var.args != NULL && var.args[i] != NULL)
	{
		write(1, var.args[i], ft_strlen(var.args[i]));
		if (var.args[i + 1] != NULL)
			write(1, " ", 1);
	}
	if (var.option != NULL)
		write(1, "\n", 1);
	if (errno == 0)
		*retv = 0;
	else
		*retv = 1;
}
