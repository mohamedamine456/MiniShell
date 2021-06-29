/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_command_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:31:42 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/29 19:27:47 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	add_cmd_args(t_cmd *cmd, char *tab)
{	
	if (cmd->args == NULL)
	{
		cmd->args = ft_split(cmd->name, '\0');
		cmd->args = ft_resize_tab(cmd->args, ft_strdup(tab));
	}
	else
		cmd->args = ft_resize_tab(cmd->args, ft_strdup(tab));
	free(tab);
}

int	ft_check(t_cmd *cmd, char *str)
{
	char	**tab;
	int		i;

	i = -1;
	tab = ft_split_white_spaces(str);
	if (cmd->name == NULL && ft_strlen_tab(tab) > 1)
		i = 0;
	ft_free_args(tab);
	return (i);
}
