/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isbuilt_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:30:21 by eel-orch          #+#    #+#             */
/*   Updated: 2021/04/27 12:30:23 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int isbuilt_in(char *cmd)
{
	int i;

	i = 0;
	if ((i = ft_strcmp(cmd, "echo")) == 0)
		return (B_ECHO);
	else if ((i = ft_strcmp(cmd, "export")) == 0)
		return (B_EXPORT);
	else if ((i = ft_strcmp(cmd, "env")) == 0)
		return (B_ENV);
	else if ((i = ft_strcmp(cmd, "exit")) == 0)
		return (B_EXIT);
	else if ((i = ft_strcmp(cmd, "cd")) == 0)
		return (B_CD);
	else if ((i = ft_strcmp(cmd, "unset")) == 0)
		return (B_UNSET);
	else if ((i = ft_strcmp(cmd, "pwd")) == 0)
		return (B_PWD); 
	return (0);
}
