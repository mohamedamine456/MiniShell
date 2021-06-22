/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:01:30 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/18 09:52:06 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	ft_cd(t_builtin_vars var, int *retv)
{
	char	*dest_path;

	if (var.args != NULL && var.args[1] != NULL
		&& ft_strcmp(var.args[1], "--"))
	{
		if (!ft_strcmp(var.args[1], "-"))
		{
			ft_cd_oldpwd(var, retv);
			return ;
		}
		else
		{
			if (!ft_strcmp(var.args[1], ""))
			{
				free(var.args[1]);
				var.args[1] = ft_strdup(".");
			}
			dest_path = ft_strdup(var.args[1]);
		}
	}
	else
		dest_path = search_env(ft_strdup("HOME"), *(var.envp));
	if (dest_path != NULL)
		ft_cd_helper(var, dest_path, retv);
	else
	{
		write(1, "MiniShell: cd: HOME not set\n", 28);
		*retv = 1;
	}
	free(dest_path);
}

void	ft_cd_helper(t_builtin_vars var, char *dest_path, int *retv)
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

void	ft_cd_oldpwd(t_builtin_vars var, int *retv)
{
	char	*oldpwd;

	oldpwd = search_env(ft_strdup("OLDPWD"), *(var.envp));
	if (oldpwd == NULL || !ft_strcmp(oldpwd, ""))
	{
		write(1, "Minishell: cd: OLDPWD not set\n", 30);
		*retv = 1;
		return ;
	}
	else
	{
		ft_cd_helper(var, oldpwd, retv);
		ft_pwd(var, retv);
		free(oldpwd);
		return ;
	}
}

int	set_oldpwd(char ***envp)
{
	char	*pwd;
	int		i;
	char	**table;
	char	**tmp;

	pwd = search_env(ft_strdup("PWD"), *envp);
	i = 0;
	table = *envp;
	while (table != NULL && table[i] != NULL)
	{
		tmp = ft_split(table[i], '=');
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
	char	**table;
	char	**tmp;
	char	*curr_path;

	i = 0;
	table = *envp;
	while (table != NULL && table[i] != NULL)
	{
		tmp = ft_split(table[i], '=');
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
