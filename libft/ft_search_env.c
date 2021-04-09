/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:50:29 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/09 17:54:21 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		if (tab != NULL && tab[0] != NULL)
		{
			if (!ft_strcmp(str, tab[0]))
			{
				new_str = ft_substr(envp[i], ft_strlen(tab[0]) + 1,
						ft_strlen(envp[i]) - ft_strlen(tab[0]) - 1);
				ft_free_args(tab);
				break ;
			}
			ft_free_args(tab);
		}
		i++;
	}
	free(str);
	return (new_str);
}
