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

#include "../parse/parse.h"

void print_cmd(t_cmd *cmd)
{
	int i;
	t_cmd  *tmp;
	tmp = cmd;

	while (tmp)
	{
		i = 0;
		printf("\n============ NEW CMD ================\n");
		printf("cmd == [%s]\n", tmp->name);
		printf("===inputs===\n");
		if (tmp->input == NULL)
			printf("NAN\n");
		else
		{
			i = 0;
			t_input *in = tmp->input;
			while (in != NULL)
			{
				printf("class == %d [%s] ", i, in->file);
				in = in->next;
				i++;
			}
			printf("\n");
		}
		printf("===options===\n");
		if (tmp->option == NULL)
			printf("NAN\n");
		else
			printf(" == %s \n", tmp->option);
		i = 0;
		printf("===args===\n");
		if (tmp->args == NULL)
			printf("NAN");
		else
			while (tmp->args[i] != NULL)
			{
				printf(" |%s|", tmp->args[i]);
				i++;
			}
		printf("\n===outputs===\n");
		if (tmp->output == NULL)
			printf("NAN\n");
		else
		{
			t_output *out = tmp->output;
			while (out != NULL)
			{
				printf("type == |%d| file == |%s| pointer value == %p\n", out->type, out->file, out->next);
				out = out->next;
			}
			printf("\n");
		}
		tmp = tmp->next;
	}
}
