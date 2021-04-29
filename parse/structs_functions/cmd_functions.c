# include "structs_functions.h"

void	add_back_cmd(t_cmd **cmds, t_cmd *new)
{
	t_cmd *cmd;

	cmd = *cmds;
	if (cmd == NULL)
		*cmds = new;
	else
	{
		cmd = last_cmd(*cmds);
		cmd->next = new;
	}
}

void	clear_cmds(t_cmd **cmds)
{
	t_cmd	*cmd1;
	t_cmd	*cmd2;

	cmd1 = *cmds;
	while (cmd1 != NULL)
	{
		cmd2 = cmd1->next;
		if (cmd1->name != NULL)
			free(cmd1->name);
		if (cmd1->option != NULL)
			free(cmd1->option);
		if (cmd1->args != NULL)
			ft_free_args(cmd1->args);
		if (cmd1->input != NULL)
			clear_inputs(&(cmd1->input));
		if (cmd1->output != NULL)
			clear_outputs(&(cmd1->output));
		free(cmd1);
		cmd1 = NULL;
		cmd1 = cmd2;
	}
	cmds = NULL;
}

t_cmd	*last_cmd(t_cmd *cmd)
{
	if (cmd != NULL)
	{
		while (cmd->next != NULL)
			cmd = cmd->next;
	}
	return (cmd);
}

t_cmd      *new_cmd()
{
	t_cmd *cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->name = NULL;
	cmd->option = NULL;
	cmd->args = NULL;
	cmd->input = NULL;
	cmd->output = NULL;
	cmd->next = NULL;
	return (cmd);
}

int		size_cmds(t_cmd *cmds)
{
	int i;

	i = 0;
	while (cmds != NULL)
	{
		i++;
		cmds = cmds->next;
	}
	return (i);
}
