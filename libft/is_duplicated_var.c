/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dulicated_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 10:21:49 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/17 10:22:16 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_duplicated_var(char **env, char *var)
{
	char 	**table;
	char	**var_key;
	int		is_duplicated;
	int		i;

	is_duplicated = -1;
	i = 0;
	table = NULL;
	var_key = ft_split(var, '=');
	while (env[i] && is_duplicated == -1)
	{
		table = ft_split(env[i], '=');
		if (ft_strcmp(table[0], var_key[0]) == 0)
			is_duplicated = i;
		ft_free_args(table);
		i++;
	}
	ft_free_args(var_key);
	return (is_duplicated);
}
