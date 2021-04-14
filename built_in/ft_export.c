#include "built_in.h"

int	isvalid_var(char *str)
{
    int i;

    if (ft_isdigit(str[0]) != 1 && str[0] != '_')
	return (-1);
    i = 1;
    while (str[i] != '\0')
    {
	if (str[i] == '-' || str[i] == '*' || str[i] == '!')
	    return (-1);
	i++;
    }
    return (0);
}

char	*to_var(char *arg)
{
    int i;

    i = ft_strstri((const char *)arg, "=");
    if (i == -1)
	return (ft_strjoin(ft_strdup(arg), "=''"));
    return (arg);
}

void	ft_export(t_builtin_vars var, int *retv)
{
    char	**sorted_env;
    char	**tmp;
    int		i;

    i = 0;
    *retv = 0;
    if (var.args == NULL)
    {
	sorted_env = sort_strings(var.envp);
	ft_print_args(sorted_env);
	*retv = 0;
	//free sorted args
    }
    else
    {
	while (var.args[i] != NULL)
	{
	    if (isvalid_var(var.args[i]) == 0)
	    {
		tmp = var.envp;
		var.envp = ft_jointabstr(var.envp, var.args[i]);
		//free tmop
		if (*retv != -1)
		    *retv = 0;
	    }
	    else
		*retv = -1;//invalide identifier
	    i++;
	}
    }
}
