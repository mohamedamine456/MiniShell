/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:47:37 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/21 13:28:28 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		**get_pipes(t_cmd *cmd)
{
	int cmd_size;
	int **pipes;
	int	i;

	i = 0;
	cmd_size = size_cmds(cmd);
	pipes = (int **)malloc(sizeof(int *) * (cmd_size));
	while (i < cmd_size)
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	return (pipes);
}

int		dup_pipes(t_cmd *cmd, int in, int out, int i)
{
	if (cmd->next != NULL)
	{
		//write(2, "dup fd[1] with  std_out\n", ft_strlen("dup fd[1] with  std_out\n"));
		dup2(out, 1);
		close(out);
	}
	if (i != 0)
	{
		//write(2, "dup fd[0] with std_in\n", ft_strlen("dup fd[0] with std_in\n"));
		dup2(in, 0);
		close(in);
	}
	return (0);
}

void	command_not_found(char *str)
{
	write(2, "minishell: ", ft_strlen("minishell: "));
	write(2, str, ft_strlen(str));
	write(2, ": command not found\n", ft_strlen(": command not found") + 1);
	exit(127);
}

void	execve_error(void)
{
	char *error_msg;

	error_msg = strerror(errno);
	write(2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
	exit(126);
}

void	search_execute(t_cmd *cmd, char **env)
{
	char 	*path;
	int 	is_duplicated;

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

void	redirect_std_in_out(t_cmd *cmd, int cmd_index, int in, int *fd)
{
	int error;

	error = 0;
	error = dup_pipes(cmd, in, fd[1], cmd_index);
	error = open_outputs(cmd->redirection);
	if (error == -1)
		exit (1);
}

int		get_exit_status(int status)
{
	int exit_status;

	exit_status = WIFEXITED(status);
	if (exit_status != 0)
		return (WEXITSTATUS(status));
	exit_status = WIFSIGNALED(status);
	if (exit_status != 0)
		return (128 + WTERMSIG(status));
	return (0);
}

int		ft_exec_nested_cmd(t_cmd *cmd, char ***env)
{
	t_cmd	*tmp;
	int		*fd;
	int		in;
	int		status;
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
			if (tmp->args == NULL)
				exit (0);
			if (contain_slaches(tmp->args[0]) == 0)
			{
				if (isbuilt_in(tmp->args[0]))
					exit(exec_builtin(tmp, env));
				search_execute(tmp, *env);
			}
			execve(tmp->args[0], tmp->args, *env);
			execve_error();
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
	return (get_exit_status(status));
}

//int main(int argc, char **argv, char **envp)
//{
// 	t_cmd *cmd;
// 	char *str = "echo bonjour > test > je > suis";
// 	char **table = ft_split(str, 32);
// 	cmd = fill_command(table);
// 	//print_cmd(cmd);
// 	char **dup_env = ft_tabdup(envp);
//	printf("\n");
// 	write(1, "==== this is execcution result ====\n", ft_strlen("==== this is execcution result ====\n"));
//	ft_exec_nested_cmd(cmd, &dup_env);
//}

