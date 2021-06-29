/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:50:29 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/29 10:19:49 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	search_env_helper(char **tab, char **envp, char **new_str, char *str)
{
	if (tab != NULL && tab[0] != NULL)
	{
		if (!ft_strcmp(str, tab[0]))
		{
			*new_str = ft_substr(envp[0], ft_strlen(tab[0]) + 1,
					ft_strlen(envp[0]) - ft_strlen(tab[0]) - 1);
			ft_free_args(tab);
			return (0);
		}
		ft_free_args(tab);
	}
	return (1);
}

char	*search_env(char *str, char **envp)
{
	int		i;
	char	*new_str;
	char	**tab;

	i = 0;
	tab = NULL;
	new_str = NULL;
	if (str == NULL || envp == NULL)
		return (NULL);
	while (envp[i] != NULL)
	{
		tab = ft_split(envp[i], '=');
		if (!search_env_helper(tab, envp + i, &new_str, str))
			break ;
		i++;
	}
	free(str);
	return (new_str);
}
