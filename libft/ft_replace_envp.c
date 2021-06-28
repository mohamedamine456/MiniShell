/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_envp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:50:03 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/28 15:04:06 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_replace_envp(const char *name, char *value, char ***envp)
{
	int		i;
	char	**tab;
	char	**tmp;
	char	*new_val;

	i = 0;
	tab = *envp;
	while (tab != NULL && tab[i] != NULL)
	{
		tmp = ft_split(tab[i], '=');
		if (!ft_strcmp(name, tmp[0]))
		{
			free((*envp)[i]);
			new_val = ft_strjoin(ft_strdup(name), "=");
			(*envp)[i] = ft_strjoin(new_val, value);
			ft_free_args(tmp);
			return (0);
		}
		ft_free_args(tmp);
		i++;
	}
	return (1);
}
