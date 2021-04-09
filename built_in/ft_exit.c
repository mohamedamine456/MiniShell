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
            //print_error(error);
            exit(number);
        }
        else
        {
            number = 0;
            *retv = 1;
            //print_error(error); // too many arguments
        }
    }
}
