/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 08:35:02 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/22 09:53:14 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	ft_env(t_builtin_vars var, int *retv)
{
	int		i;
	char	**envp;

	i = 0;
	envp = *(var.envp);
	while (envp != NULL && envp[i] != NULL)
	{
		if (ft_isenv(envp[i]))
		{
			write(1, envp[i], ft_strlen(envp[i]));
			if (envp[i + 1] != NULL)
				write(1, "\n", 1);
		}
		i++;
	}
	*retv = 0;
}

void	add_env_path(t_builtin_vars var)
{
	int		i;
	char	**tab;
	char	*tmp_free;
	char	*tmp;
	char	*curr_path;

	i = 0;
	while (var.envp[0] != NULL && var.envp[0][i] != NULL)
	{
		tab = ft_split(var.envp[0][i], '=');
		if (tab != NULL && tab[0] != NULL && !ft_strcmp(tab[0], "PATH"))
		{
			tmp = ft_substr(var.envp[0][i], 5, ft_strlen(var.envp[0][i]) - 5);
			curr_path = getcwd(NULL, 0);
			if (curr_path != NULL)
			{
				curr_path = ft_strjoin(curr_path, ":");
				tmp_free = tmp;
				tmp = ft_strjoin(curr_path, tmp);
				free(tmp_free);
			}
			var.envp[0][i] = ft_strjoin(ft_strdup("PATH="), tmp);
			free(tmp);
			ft_free_args(tab);
			return ;
		}
		ft_free_args(tab);
		i++;
	}
}


int main(int argc, char **args, char **envp)
{
	t_builtin_vars var;
	int retv;

	var.args = NULL;
	var.envp = &envp;
	var.option = NULL;
	add_env_path(var);
	ft_env(var, &retv);
}
