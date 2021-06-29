/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:47:37 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/29 20:36:41 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void	search_execute(t_cmd *cmd, char **env)
{
	char	*path;
	int		is_duplicated;

	path = NULL;
	is_duplicated = is_duplicated_var(env, "PATH");
	if (is_duplicated != -1)
	{
		path = command_path(cmd->args[0], env);
		if (path != NULL)
		{
			execve(path, cmd->args, env);
			execve_error();
		}
	}
	execve(cmd->args[0], cmd->args, env);
	if (errno == EACCES)
		execve_error();
	command_not_found(cmd->args[0]);
}

void	exec_child(t_cmd *tmp, char ***env)
{
	if (tmp->args == NULL)
		exit (0);
	if (contain_slaches(tmp->args[0]) == 0)
	{
		if (isbuilt_in(tmp->args[0]))
			exit(exec_builtin(tmp, env));
		search_execute(tmp, *env);
	}
	if (tmp->args[0] != NULL)
		execve(tmp->args[0], tmp->args, *env);
	execve_error();
}

int	ft_exec_nested_cmd(t_cmd *cmd, char ***env)
{
	t_cmd	*tmp;
	int		*fd;
	int		in;
	int		status = 0;
	int		std_in = dup(0);
	int		std_out = dup(1);
	int		i;
	pid_t	pid;

	tmp = cmd;
	in = 0;
	i = 0;
	fd = (int *)malloc(sizeof(int) * 2);
	while (tmp != NULL)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			redirect_std_in_out(tmp, i, in, fd);
			exec_child(tmp, env);
		}
		wait(&status);
		in = fd[0];
		close(fd[1]);
		tmp = tmp->next;
		i++;
		dup2(std_out,1);
		dup2(std_in, 0);
	}
	close(fd[0]);
	free(fd);
	return (get_exit_status(status));
}
