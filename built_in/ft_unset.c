#include "built_in.h"

void    ft_unset(t_builtin_vars var, int *retv)
{
    int i;

    i = 0;
    while (var.args != NULL && *(var.envp) != NULL && var.args[i] != NULL)
    {
        *(var.envp) = remove_env(var.args[i], *(var.envp));
        i++;
    }
    if (var.args != NULL && var.args[i] == NULL)
        *retv = 0;
    else
        *retv = 1;
}

char	**remove_env(char *str, char **envp)
{
	char	**tab;
	int		i;

	i = 0;
	tab = NULL;
	if (envp == NULL || str == NULL)
		return (envp);
	while (envp[i] != NULL)
	{
		tab = ft_split(envp[i], '=');
		if (!ft_strcmp(tab[0], str))
		{
			while (envp[i + 1] != NULL)
			{
				envp[i] = envp[i + 1];
				i++;
			}
			envp[i] = NULL;
		}
		ft_free_args(tab);
		i++;
	}
	return (envp);
}

//int main(int argc, char **args, char **envp)
//{
//	int i;
//
//	i = 0;
//	if (argc > 1)
//	{
//		envp = remove_env(args[1], envp);
//		while (envp[i] != NULL)
//		{
//			write(1, envp[i], ft_strlen(envp[i]));
//			write(1, "\n", 1);
//			i++;
//		}
//	}
//}
