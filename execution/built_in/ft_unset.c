/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:37:52 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/23 11:39:13 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	ft_unset(t_builtin_vars var, int *retv)
{
	int	i;

	i = 1;
	*retv = 0;
	while (var.args != NULL && *(var.envp) != NULL && var.args[i] != NULL)
	{
		if (!valid_identifier(var.args[i]))
			*(var.envp) = remove_env(var.args[i], *(var.envp));
		else
		{
			not_valid_identifier(var.args[i]);
			*retv = 1;
		}
		i++;
	}
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

int	valid_identifier(char *identifier)
{
	int	i;

	i = 1;
	if (!ft_isalpha(identifier[0]) && identifier[0] != '_')
		return (1);
	while (identifier[i] != '\0')
	{
		if (!ft_isalnum(identifier[i]) && identifier[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

void	not_valid_identifier(char *identifier)
{
	write(2, "MiniShell: ", 11);
	write(2, "unset: `", 8);
	write(2, identifier, ft_strlen(identifier));
	write(2, "': not a valid identifier\n", 26);
}
