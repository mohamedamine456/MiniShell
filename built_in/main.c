/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:24:33 by eel-orch          #+#    #+#             */
/*   Updated: 2021/05/23 19:34:07 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse/parse.h"


void	add(t_cmd *cmd)
{
	cmd->args = ft_split("hello world hello hello eofjefefsf sfd fsff", 32);
}

int main()
{
	t_cmd *cmd;

	cmd = (t_cmd *)malloc(sizeof(cmd));
	cmd->args = ft_split("hello world", 32);
	add(cmd);
	while (*(cmd->args) != NULL)
	{
		printf("%s", *(cmd->args));
		*(cmd->args)++;
	}
}
