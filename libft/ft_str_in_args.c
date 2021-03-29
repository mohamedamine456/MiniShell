# include "libft.h"

int		ft_str_in_args(char *str, char **args)
{
	int i;

	i = 0;
	if (str == NULL || args == NULL)
		return (0);
	while (args[i] != NULL)
	{
		if (!ft_strcmp(str, args[i]))
			return (1);
		i++;
	}
	return (0);
}
