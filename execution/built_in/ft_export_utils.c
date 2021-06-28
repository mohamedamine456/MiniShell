/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:56:34 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/28 14:56:41 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void ft_export_errors(char *identifier, int *retv)
{
	write(2, "minishell: export ", ft_strlen("minishell: export "));
	write(2, identifier, ft_strlen(identifier));
	write(2, ": not a valid identifier\n", ft_strlen(": not a valid identifier") + 1);
	*retv = -1;
}
