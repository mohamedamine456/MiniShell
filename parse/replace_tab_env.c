/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_tab_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:46:58 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/30 18:47:32 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	**replace_cmd_env(char **tab_cmd, char **envp, int retv)
{
	int	i;

	i = 0;
	if (*envp == NULL)
		return (tab_cmd);
	while (tab_cmd != NULL && tab_cmd[i] != NULL)
	{
		tab_cmd[i] = trim_replace(tab_cmd[i], envp, retv);
		i++;
	}
	return (tab_cmd);
}
