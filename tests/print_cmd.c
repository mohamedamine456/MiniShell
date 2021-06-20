/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:46:17 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/20 19:06:55 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse/parse.h"

void print_cmd(t_cmd *cmd)
{
	int i;
	t_cmd  *tmp;
	t_redirection *redi;
	tmp = cmd;

	while (tmp)
	{
		i = 0;
		printf("\n============ NEW CMD ================\n");
		printf("cmd == [%s]\n", tmp->name);
		printf("===inputs===\n");
		if (tmp->input == NULL)
			printf("NAN\n");
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
		redi = tmp->redirecction;
		printf("==== redirection ===\n");
		while(redi!= NULL)
		{
			printf("type == %d", redi->type);
			printf("file == %s\n", redi->file);
			redi = redi->next;
		}
	}
}
