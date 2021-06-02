/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:18:50 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/02 16:34:10 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	add_cmd_name(char **cmd_name, char *name)
{
	*cmd_name = ft_strdup(name);
}

void	add_cmd_output(t_cmd *cmd, char *str, char *file)
{
	int			i;
	int			which_output;
	t_output	*tmp;

	i = 0;
	which_output = ft_isoutput(str);
	tmp = new_output();
	tmp->file = ft_strdup(file);
	if (which_output == 2)
		tmp->type = DOUBLE_REDIRECTION;
	else
		tmp->type = SIMPLE_REDIRECTION;
	add_output_back(&(cmd->output), tmp);
}

void	add_cmd_args(t_cmd *cmd, char *tab)
{
	if (cmd->args == NULL)
	{
		cmd->args = ft_split(cmd->name, '\0');
		cmd->args = ft_resize_tab(cmd->args, ft_strdup(tab));
	}
	else
		cmd->args = ft_resize_tab(cmd->args, ft_strdup(tab));
}

void	add_cmd_input(t_cmd *cmd, char *file)
{
	t_input	*tmp;

	tmp = (t_input *)malloc(sizeof(t_input));
	tmp = new_input();
	tmp->file = ft_strdup(file);
	tmp->next = NULL;
	add_input_back(&(cmd->input), tmp);
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

void	fill(t_cmd *cmd, char *str)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split_white_spaces(str);
	while (tab[i])
	{
		if (i == 0)
			cmd->args = ft_split(tab[i], '\0');
		else if (is_option(tab[i], cmd->args[0]) != -1)
			add_cmd_options(&(cmd->option), tab[i]);
		else
			add_cmd_args(cmd, tab[i]);
		i++;
	}
	ft_free_args(tab);
}

t_cmd	*fill_command(char **tab)
{
	t_cmd	*cmd;
	t_cmd	*pars;
	int		i;

	i = 0;
	pars = new_cmd();
	cmd = pars;
	while (tab[i] != NULL)
	{
		if (ft_check(pars, tab[i]) != -1)
			fill(cmd, tab[i]);
		else if (ft_is_string(tab[i]) != -1 && pars->args == NULL)
			cmd->args = ft_split(tab[i], '\0');
		else if (pars->args != NULL && (is_option(tab[i], pars->args[0]) != -1) && pars->args[1] == NULL)
			add_cmd_options(&(pars->option), tab[i]);
		else if (ft_isoutput(tab[i]) != -1)
		{
			add_cmd_output(pars, tab[i], tab[i + 1]);
			i++;
		}
		else if (ft_isinput(*tab[i]) != -1)
		{
			add_cmd_input(pars, tab[i + 1]);
			i++;
		}
		else if (ft_ispipe(tab[i]) != -1)
		{
			pars->next = new_cmd();
			pars = pars->next;
		}
		else
			add_cmd_args(pars, ft_strdup(tab[i]));
		if (tab[i] != NULL)
			i++;
	}
	return (cmd);
}

