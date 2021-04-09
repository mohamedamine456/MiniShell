#include "built_in.h"

void	ft_exit(t_builtin_vars var, int *retv)
{
	if (ft_size_args(var.args) == 0)
	{
		exit();
		*retv = 0;
	}
	else if (ft_size_args(var.args))
}
