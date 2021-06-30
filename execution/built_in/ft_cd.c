/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:20:49 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/30 11:44:38 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	ft_cd(t_builtin_vars var, int *retv)
{
	char	*dest_path;

	dest_path = NULL;
	if (var.args != NULL && (var.args[1] == NULL
			|| (var.args[1] != NULL && !ft_strcmp(var.args[1], "--"))))
	{
		dest_path = search_env(ft_strdup("HOME"), *(var.envp));
		if (dest_path == NULL)
		{
			write(2, "MiniShell: cd: HOME not set\n", 28);
			*retv = 1;
			return ;
		}
		ft_cd_normal_case(var, dest_path, retv);
	}
	else if (var.args != NULL && var.args[1] != NULL)
	{
		if (!ft_strcmp(var.args[1], "-"))
		{
			ft_cd_oldpwd(var, retv);
			*retv = 0;
		}
		else
			ft_cd_normal_case(var, dest_path, retv);
	}
}

void	ft_cd_normal_case(t_builtin_vars var, char *dest_path, int *retv)
{
	if (var.args != NULL && var.args[1] != NULL && !ft_strcmp(var.args[1], ""))
	{
		free(var.args[1]);
		var.args[1] = ft_strdup(".");
	}
	if (dest_path == NULL)
		dest_path = ft_strdup(var.args[1]);
	if (chdir(dest_path) != 0)
		ft_builtin_errors("cd", errno, retv);
	else
	{
		if (!change_oldpwd(var.envp) && !change_pwd(var.envp))
			*retv = 0;
		else
			*retv = 1;
		free(dest_path);
	}
}

int	change_oldpwd(char ***envp)
{
	char	*tmp;

	tmp = search_env(ft_strdup("PWD"), *envp);
	if (tmp != NULL)
	{
		if (!ft_replace_envp("OLDPWD", tmp, envp))
		{
			free(tmp);
			return (0);
		}
		free(tmp);
		return (1);
	}
	return (1);
}

int	change_pwd(char ***envp)
{
	char	*curr_path;

	curr_path = getcwd(NULL, 0);
	if (curr_path != NULL)
	{
		if (!ft_replace_envp("PWD", curr_path, envp))
		{
			free(curr_path);
			return (0);
		}
		free(curr_path);
		return (1);
	}
	return (1);
}

void	ft_cd_oldpwd(t_builtin_vars var, int *retv)
{
	char	*oldpwd;

	oldpwd = search_env(ft_strdup("OLDPWD"), *(var.envp));
	if (oldpwd == NULL || !ft_strcmp(oldpwd, ""))
	{
		write(2, "Minishell: cd: OLDPWD not set\n", 30);
		*retv = 1;
		return ;
	}
	else
	{
		ft_cd_normal_case(var, ft_strdup(oldpwd), retv);
		ft_pwd(var, retv);
		free(oldpwd);
		return ;
	}
}
