/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:46:17 by eel-orch          #+#    #+#             */
/*   Updated: 2021/03/30 17:02:44 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void print_cmd(t_cmd cmd)
{
	int i;

	i = 0;
	printf("\n============================\n");
	printf("cmd == [%s]\n", cmd.name);
	printf("options == [%s]\n", cmd.option);
	printf("args ==");
	if (cmd.args == NULL)
		printf("NAN\n");
	else
	{
		while (cmd.args[i] != NULL)
		{
			printf(" |%s|", cmd.args[i]);
			i++;
		}
		printf("\n");
	}
	printf("inputs ==");
	if (cmd.input == NULL)
		printf("NAN\n");
	else
	{
		i = 0;
		while (cmd.input[i] != NULL)
		{
			printf(" |%s|", cmd.input[i]);
			i++;
		}
		printf("\n");
	}
	printf("outputs");
	if (cmd.output == NULL)
		printf("NAN\n");
	else
	{
		i = 0;
		while (cmd.output[i] != NULL)
		{
			printf(" |%s|", cmd.output[i]);
			i++;
		}
		printf("\n");
	}
}
