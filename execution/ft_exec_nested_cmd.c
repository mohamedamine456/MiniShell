/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:47:37 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/16 20:40:24 by eel-orch         ###   ########.fr       */
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
}

void	search_execute(t_cmd *cmd, char **env)
{
	char 	*path;
	char	**path_env;
	char	*curent_dir;
	int 	is_duplicated;

	is_duplicated = is_duplicated_var(env, "PATH");
	if (is_duplicated != -1)
	{
		path = command_path(cmd->args[0], env);
		//write(2, path, ft_strlen(path));
		write(2, "error\n", 6);
		execve(path, cmd->args, env);
		execve_error();
		exit(126);
	}
	curent_dir = NULL;
	curent_dir = getcwd(curent_dir, 0);
	path_env = ft_split(curent_dir, '\0');
	path = command_path(cmd->args[0], path_env);
	free(curent_dir);
	ft_free_args(path_env);
	if (path != NULL)
	{
		write(2, "error\n", 6);
		execve(path, cmd->args, env);
		execve_error();
		exit(126);
	}
	command_not_found(cmd->args[0]);
}

				//SEARCH FOR THE COMMAND
					//SUCCESSFUL SEARCH
						// CALL EXECVE
							//fails ==> execute _126
							//succes ==> execute cmd and exit  with the right status
					//UNSUCCECFULL SEARCH
						//exit with status _127 (COMMAND NOT FOUND)

int		ft_exec_nested_cmd(t_cmd *cmd, char ***env)
{
	t_cmd	*tmp;
	int		fd[2];
	int		in;
	int		out;
	int		std_in = dup(0);
	int		std_out = dup(1);
	char	*path;
	int		i;
	pid_t	pid;

	tmp = cmd;
	in = 0;
	out = 1;
	i = 0;
	while (tmp != NULL)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			dup_pipes(tmp, in, fd[1], i);
			open_inputs(tmp->input);
			open_outputs(tmp->output);
			if (contain_slaches(tmp->args[0]) == 0)
			{
				if (isbuilt_in(tmp->args[0]))
					return (exec_builtin(tmp, env));
				search_execute(tmp, *env);
			}
			execve(tmp->args[0], tmp->args, *env);
			execve_error();
			exit(126);
		}
		in = fd[0];
		close(fd[1]);
		wait(NULL);
		tmp = tmp->next;
		i++;
		dup2(std_out,1);
		dup2(std_in, 0);
	}
	close(fd[0]);
	return (0);
}

//int main(int argc, char **argv, char **envp)
//{
// 	t_cmd *cmd;
// 	char *str = "echo hello | grep h";
// 	char **table = ft_split(str, 32);
// 	cmd = fill_command(table);
// 	print_cmd(cmd);
// 	char **dup_env = ft_tabdup(envp);
//	write(1, "\n", 1);
// 	ft_exec_nested_cmd(cmd, &dup_env);
//}
