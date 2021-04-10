/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:49:12 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/10 11:31:17 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	ft_builtin_errors(char *errorr, int *retv)
{
	*retv = 1;
	if (errorr != NULL)
		write(1, errorr, ft_strlen(errorr));
}
