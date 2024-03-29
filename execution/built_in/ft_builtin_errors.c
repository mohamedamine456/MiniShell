/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:49:12 by mlachheb          #+#    #+#             */
/*   Updated: 2021/07/02 11:44:22 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	ft_builtin_errors(const char *name, int err, int *retv)
{
	char	*error_str;

	error_str = strerror(err);
	*retv = 1;
	write(2, "MiniShell: ", 11);
	write(2, name, ft_strlen(name));
	write(2, ": ", 2);
	write(2, error_str, ft_strlen(error_str));
	write(2, "\n", 1);
}

void	home_not_set(char *error, int *retv)
{
	write(2, error, ft_strlen(error));
	*retv = 1;
}
