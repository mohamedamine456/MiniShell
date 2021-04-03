/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:46:17 by eel-orch          #+#    #+#             */
/*   Updated: 2021/04/03 14:25:13 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void print_cmd(t_cmd cmd)
{
	int i;

	i = 0;
	printf("\n============================\n");
	printf("cmd == [%s]\n", cmd.name);
	printf("===inputs===\n");
	if (cmd.input == NULL)
		printf("NAN\n");
	else
	{
		i = 0;
		t_input *in = cmd.input;
		while (in != NULL)
		{
			printf("class == %d [%s] ", i, in->file);
			in = in->next;
			i++;
		}
		printf("\n");
	}
	printf("===options===\n");
	if (cmd.option == NULL)
		printf("NAN\n");
	else
		printf(" == %s \n", cmd.option);
	i = 0;
	printf("===args===\n");
	if (cmd.args == NULL)
		printf("NAN");
	else
		while (cmd.args[i] != NULL)
		{
			printf(" |%s|", cmd.args[i]);
			i++;
		}
	printf("\n===outputs===\n");
	if (cmd.output == NULL)
		printf("NAN\n");
	else
	{
		t_output *out = cmd.output;
		while (out != NULL)
		{
			printf("type == |%d| file == |%s| pointer value == %p\n", out->type, out->file, out->next);
			out = out->next;
		}
		printf("\n");
	}
}
