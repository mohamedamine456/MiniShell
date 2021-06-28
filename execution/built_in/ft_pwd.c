/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:33:57 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/28 13:33:59 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	ft_pwd(t_builtin_vars var, int *retv)
{
	char	*curr_path;

	var.option = NULL;
	curr_path = getcwd(NULL, 0);
	if (curr_path == NULL)
	{
		ft_builtin_errors("pwd", errno, retv);
	}
	else
	{
		write(1, curr_path, ft_strlen(curr_path));
		free(curr_path);
		*retv = 0;
	}
	write(1, "\n", 1);
}
