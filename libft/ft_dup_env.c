/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 09:45:33 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/28 14:47:41 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_dup_env(char **envp)
{
	char	**new_envp;
	char	**tab;
	int		i;

	i = 0;
	new_envp = ft_tabdup(envp);
	while (new_envp != NULL && new_envp[i] != NULL)
	{
		tab = ft_split(new_envp[i], '=');
		if (tab != NULL && tab[0] != NULL)
		{
			if (!ft_strcmp(tab[0], "OLDPWD"))
			{
				free(new_envp[i]);
				new_envp[i] = ft_strdup("OLDPWD");
				ft_free_args(tab);
				return (new_envp);
			}
		}
		ft_free_args(tab);
		i++;
	}
	new_envp = ft_resize_tab(new_envp, ft_strdup("OLDPWD"));
	return (new_envp);
}
