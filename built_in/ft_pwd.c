#include "built_in.h"

void	ft_pwd(t_builtin_vars var, int *retv)
{
	char	*curr_path;

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
