# include "libft.h"

void	ft_print_args(char **args)
{
	int	i = 0;

	while (args != NULL && args[i] != NULL)
	{
		write(1, "{", 1);
		write(1, args[i], ft_strlen(args[i]));
		write(1, "}", 1);
		i++;
	}
}
