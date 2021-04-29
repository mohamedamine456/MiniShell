/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:37:52 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/29 16:38:09 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	ft_unset(t_builtin_vars var, int *retv)
{
	int	i;

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
