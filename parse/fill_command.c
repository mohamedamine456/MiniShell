/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:18:50 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/29 10:31:43 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	add_cmd_redirection(t_cmd *cmd, char *str, char *file, int *index)
{
	int				i;
	int				type;
	t_redirection	*tmp;

	i = 0;
	type = is_redirection(str);
	tmp = new_redirection();
	tmp->type = type;
	tmp->file = ft_strdup(file);
	add_redirection_back(&(cmd->redirection), tmp);
	(*index)++;
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

void	next_parse_cmd(t_cmd **parse_cmd)
{
	(*parse_cmd)->next = new_cmd();
	*parse_cmd = (*parse_cmd)->next;
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
		if (ft_check(pars, tab[i]) != -1 && i == 0)
			fill(pars, tab[i]);
		else if (ft_is_string(tab[i]) != -1 && pars->args == NULL)
			pars->args = ft_split(tab[i], '\0');
		else if (pars->args != NULL && (is_option(tab[i], pars->args[0]) != -1) && pars->args[1] == NULL)
			add_cmd_options(&(pars->option), tab[i]);
		else if (is_redirection(tab[i]) != -1)
			add_cmd_redirection(pars, tab[i], tab[i + 1], &i);
		else if (ft_ispipe(tab[i]) != -1)
			next_parse_cmd(&pars);
		else
			add_cmd_args(pars, ft_strdup(tab[i]));
		if (tab[i] != NULL)
			i++;
	}
	return (cmd);
}

//int main()
//{
//	char **tab = ft_split("export >> output1 << input1 > ff 
//	| grep l < grep_input > grep_output", 32);
//	t_cmd *cmd = fill_command(tab);
//	print_cmd(cmd);
//}
