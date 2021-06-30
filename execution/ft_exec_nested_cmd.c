/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:47:37 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/30 19:04:37 by eel-orch         ###   ########.fr       */
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

int	fork_and_execute(t_cmd *cmd, char ***env, int *fd)
{
	int i;
	int in;
	t_cmd *tmp;
	int pid;
	i = 0;
	in = 0;
	tmp = cmd;
	while (tmp != NULL)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			redirect_std_in_out(tmp, i, in, fd);
			exec_child(tmp, env);
		}
		close(fd[1]);
		if (i > 0)
			close(in);
		in = fd[0];
		tmp = tmp->next;
		i++;
	}
	return (pid);
}

int	ft_exec_nested_cmd(t_cmd *cmd, char ***env)
{
	int		*fd;
	int		status;
	pid_t	pid;

	status = 0;
	fd = (int *)malloc(sizeof(int) * 2);
	pid = fork_and_execute(cmd, env, fd);
	waitpid(pid, &status, 0);
	while (wait(NULL) > 0)
		;
	free(fd);
	return (get_exit_status(status));
}
