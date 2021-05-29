/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:37:52 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/18 16:43:54 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	ft_unset(t_builtin_vars var, int *retv)
{
	int	i;

	i = 1;
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
	char	**table;
	int		i;

	i = 0;
	table = NULL;
	if (envp == NULL || str == NULL)
		return (envp);
	while (envp[i] != NULL)
	{
		table = ft_split(envp[i], '=');
		if (!ft_strcmp(table[0], str))
		{
			while (envp[i + 1] != NULL)
			{
				envp[i] = envp[i + 1];
				i++;
			}
			envp[i] = NULL;
		}
		ft_free_args(table);
		i++;
	}
	return (envp);
}
