/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:01:30 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/09 16:29:43 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.c"

void	ft_cd(char **args, char *option, int *retv)
{
	char	*dest_path;
	int		size;

	if (args != NULL && args[0] != NULL)
	{
		size = ft_strlen(args[0]);
		dest_path = ft_strdup(args[0]);
	}

}
