#include "built_in.h"

void	ft_pwd(char **args, char *option, int *retv)
{
	char	*curr_path;
	int		size;

	curr_path = getcwd(NULL, 0);
	if (curr_path == NULL)
	{
		*retv = 1;
		//print_error(errno);
	}
	else
	{
		write(1, curr_path, ft_strlen(curr_path));
		free(curr_path);
		*retv = 0;
	}
}
