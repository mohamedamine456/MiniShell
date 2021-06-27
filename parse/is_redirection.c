/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:56:10 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/27 16:28:27 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int is_redirection(char *str)
{
	if (ft_strlen(str) == 0)
		return (-1);
	if (ft_strcmp(str, ">") == 0)
		return (TRUNC);
	if (ft_strcmp(str, ">>") == 0)
		return (APPEND);
	if (ft_strcmp(str, "<") == 0)
		return (INPUT);
	if (ft_strcmp(str, "<<") == 0)
		return (HERE_DOC);
	return (-1);
}

