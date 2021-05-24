/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:01:30 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/24 12:01:26 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	ft_cd(t_builtin_vars var, int *retv)
{
	char	*dest_path;

	if (var.args != NULL && var.args[1] != NULL)
		dest_path = ft_strdup(var.args[1]);
	else
		dest_path = search_env(ft_strdup("HOME"), *(var.envp));
	if (dest_path != NULL)
	{
		if (!set_oldpwd(var.envp))
			change_pwdenv(var.envp, "OLDPWD");
		if (chdir(dest_path) != 0)
			ft_builtin_errors("cd", errno, retv);
		else
		{
			if (change_pwdenv(var.envp, "PWD"))
				*retv = 0;
			else
				*retv = 1;
		}
	}
	else
	{
		write(1, "MiniShell: cd: HOME not set", 27);
		*retv = 1;
	}
	free(dest_path);
}

int		set_oldpwd(char ***envp)
{
	char	*pwd;
	int     i;
    char    **tab;
	char	**tmp;

	pwd = search_env(ft_strdup("PWD"), *envp);

    i = 0;
    tab = *envp;
    while (tab != NULL && tab[i] != NULL)
    {
        tmp = ft_split(tab[i], '=');
        if (!ft_strcmp(tmp[0], "OLDPWD"))
        { 
            if (pwd != NULL)
            {
                (*envp)[i] = ft_strjoin(ft_strdup("OLDPWD="), pwd);
				ft_free_args(tmp);
            	free(pwd);
				return (1);
			}
        }
        ft_free_args(tmp);
        i++;
    }
	return (0);
}

int	change_pwdenv(char ***envp, char *name)
{
	int		i;
	char	**tab;
	char	**tmp;
	char	*curr_path;

	i = 0;
	tab = *envp;
	while (tab != NULL && tab[i] != NULL)
	{
		tmp = ft_split(tab[i], '=');
		if (!ft_strcmp(tmp[0], name))
		{
			ft_free_args(tmp);
			curr_path = getcwd(NULL, 0);
			if (curr_path != NULL)
			{
				(*envp)[i] = ft_strjoin(ft_strjoin(ft_strdup(name), "="), curr_path);
				free(curr_path);
				return (1);
			}
		}
		ft_free_args(tmp);
		i++;
	}
	return (0);
}
