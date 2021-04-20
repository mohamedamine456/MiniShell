#include "minishell.h"

void	print_cmds(t_cmd *cmd)
{
	t_output	*out;
	t_input	*in;
	int			i;

		while (cmd != NULL)
	{
		printf("{name: %s} ", cmd->name);
		printf("{option: %s} ", cmd->option);
		printf("{arguments: ");
		i = 0;
		while (cmd->args[i] != NULL)
		{
			printf("[%s] ", cmd->args[i]);
			i++;
		}
		printf("} {outputs: ");
		out = cmd->output;
		while (out != NULL)
		{
			printf("[%s , %d] ", out->file, out->type);
			out = out->next;
		}
		in = cmd->input;
		printf("} {input: ");
		while (in != NULL)
		{
			printf("[%s]", in->file);
			in = in->next;
		}
		printf("} + ");
		cmd = cmd->next;
	}
	printf("\n");
}
