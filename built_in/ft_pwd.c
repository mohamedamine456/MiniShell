#include "built_in.h"

void	ft_pwd(t_builtin_vars var, int *retv)
{
	char	*curr_path;

	var.option = NULL;
	curr_path = getcwd(NULL, 0);
	if (curr_path == NULL)
	{
		ft_builtin_errors("pwd", errno, retv);
	}
	else
	{
		write(1, curr_path, ft_strlen(curr_path));
		free(curr_path);
		*retv = 0;
	}
	write(1, "\n", 1);
}
