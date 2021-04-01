/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:18:50 by eel-orch          #+#    #+#             */
/*   Updated: 2021/04/01 18:45:25 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parse.h"

void	add_cmd_name(char **cmd_name, char *name)
{
	//*cmd_name = ft_strdup(name);
}

void	add_cmd_output(t_cmd **cmd, char *str, char *file)
{
	int			i;
	int			which_redir;
	t_output	*tmp;
	i = 0;
	which_redir = ft_isoutput(str);
	while (tmp != NULL)
		tmp = tmp->next;
	(*cmd)->output->file = ft_strdup(file);
	(*cmd)->output = (t_output *)malloc(sizeof(t_output));
	if (which_redir == 2)
		(*cmd)->output->type = DOUBLE_REDIRECTION;
	else
		(*cmd)->output->type = SIMPLE_REDIRECTION;
	tmp->next = NULL;
}

int 	ft_ispipe(char *str)
{
	if (str[0] == '|')
		return (1);
	return (-1);
}

void	init_cmd(t_cmd *cmd)
{
	cmd->option = NULL;
	cmd->name = NULL;
	cmd->args = NULL;
	cmd->input = NULL;
	cmd->output = NULL;
}

void	add_cmd_args(char ***args, char *tab)
{
	*args = ft_resize_tab(*args, tab);
}

void	add_cmd_input(t_cmd **cmd, char *file)
{
	t_input *tmp;
	int 	i;

	tmp = (*cmd)->input;
	while (tmp != NULL)
		tmp = tmp->next;
	tmp = (t_input *)malloc(sizeof(t_input));
	tmp->file = ft_strdup(file);
	tmp->next = NULL;
}

t_cmd	*fill_command(char **tab)
{
	t_cmd	*cmd;
	int		i;

	i = 0;
	cmd = (t_cmd *)malloc(sizeof(t_cmd *));
	init_cmd(cmd);
	while (tab[i] != NULL)
	{
		if (ft_is_string(tab[i]) != -1 && cmd->name == NULL)
		{
			write(1,"ll\n", 3);
			add_cmd_name(&(cmd->name), tab[i]);
			write(1, "ll\n", 3);	
		}
		else if (ft_is_string(tab[i]) != -1 && cmd->name != NULL)
			add_cmd_args(&(cmd->args), tab[i]);
		else if (ft_isoutput(tab[i]) != -1)
		{
			add_cmd_output(&cmd, tab[i], tab[i + 1]);
			i++;
		}
		else if (ft_isinput(*tab[i]) != -1)
		{
			add_cmd_input(&cmd,tab[i + 1]);
			i++;
		}
		else if (ft_ispipe(tab[i]) != -1)
			break;
		if (tab[i] != NULL)
			i++;
	}
	return (cmd);
}

int main()
{
	int i;
	char *str = "echo > file";
	char **tab = ft_split(str, 32);
	t_cmd *cmd;
	fill_command(tab);
}
