/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:01:30 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/09 17:44:28 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.c"

void	ft_cd(t_builtin_vars var, int *retv)
{
	char	*dest_path;
	int		size;

	if (var.args != NULL && var.args[0] != NULL)
	{
		size = ft_strlen(var.args[0]);
		dest_path = ft_strdup(var.args[0]);
	}
	
}
