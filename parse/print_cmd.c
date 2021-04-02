/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:46:17 by eel-orch          #+#    #+#             */
/*   Updated: 2021/04/02 19:11:11 by eel-orch         ###   ########.fr       */
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
		printf("test\n");
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
	}
	i = 0;
	printf("\nargs ==");
	if (cmd.args == NULL)
		printf(" NAN\n");
	else
		while (cmd.args[i] != NULL)
		{
			printf(" |%s|", cmd.args[i]);
			i++;
		}
	printf("===outputs===\n");
	if (cmd.output == NULL)
		printf("NAN\n");
	else
	{
		int i = 0;
		t_output *out = cmd.output;
		while (out != NULL)
		{
			printf("type == |%d| file == |%s| pointer value == %p ", out->type, out->file, out->next);
			out = out->next;
			i++;
		}
		printf("%d", i);
		printf("\n");
	}
}
