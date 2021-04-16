#include "built_in.h"

void	ft_exit(t_builtin_vars var, int *retv)
{
    int number;

    number = 0;
	if (ft_size_args(var.args) == 0)
		exit();
	else if (ft_size_args(var.args) == 1 && ft_only_digits(var.args[0]))
    {
        number = ft_atoi(var.args[0]);
        //free alllllll
        exit(number);
    }
    else
    {
        if (!ft_only_digits(var.args[0]))
        {
            number = 255;
            write(1, "MiniShell: exit: ", 17);
			write(1, var.args[0], ft_strlen(args[0]));
			write(1, ": numeric argument required", 27);
            exit(number);
        }
        else
        {
            number = 0;
            *retv = 1;
			write(1, "MiniShell: exit: too many arguments", 35);
        }
    }
}
