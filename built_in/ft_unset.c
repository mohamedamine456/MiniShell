#include "built_in.h"

void    ft_unset(t_builtin_vars var, int *retv)
{
    int i;

    i = 0;
    while (var.args != NULL && var.envp != NULL && var.args[i] != NULL)
    {
        //var.envp = ft_remove_str_envp(var.args[i], var.envp);  // i ll write it the mornin
        i++;
    }
    if (var.args != NULL && var.args[i] == NULL)
        *retv = 0;
    else
        *retv = 1;
}
