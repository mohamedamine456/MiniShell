/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:47:37 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/03 19:23:40 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int test_file;

void	print_error()
{
	write(test_file, "error\n", 6);
	exit(0);
}

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

// -1 is for errors handling
//int		open_inputs(t_input *inputs)
//{
//	t_input *tmp;
//	int		fd;
//
//	tmp = inputs;
//	if (inputs == NULL)
//	{
//		write(fd, "no input files\n", ft_strlen("no input files\n"));
//		return (0);
//	}
//	while (tmp)
//	{
//		fd = open(tmp->file, O_RDWR |  O_APPEND | O_CREAT, 0777);;
//		if (fd == -1)
//		{
//			print_error();
//			return (-1);
//		}
//		if (dup2(fd, 0) == -1)
//		{
//			print_error();
//			close(fd);
//			return (-1);
//		}
//		tmp = tmp->next;
//	}
//	return (1);
//}

// int		open_outputs(t_output *outputs)
// {
// 	t_output	*tmp;
// 	int			fd;

// 	tmp = outputs;
// 	if (tmp == NULL)
// 		return (0);
// 	while (tmp)
// 	{
// 		if (tmp->type == SIMPLE_REDIRECTION)
// 		{

// 		}
// 		else
// 		{

// 		}
// 	}
// }

//amiiiiiiines function
//int	open_outputs(t_output *outputs)
//{
//	int	new_fd;
//	int	tmp_fd;
//
//	if (outputs == NULL)
//	{
//		write(2, "no output files\n", ft_strlen("no output files\n"));
//		return (0);
//	}
//	new_fd = 1;
//	while (outputs != NULL)
//	{
//		if (outputs->type == SIMPLE_REDIRECTION)
//			new_fd = open(outputs->file, O_RDWR | O_CREAT, 0777);
//		else if (outputs->type == DOUBLE_REDIRECTION)
//			new_fd = open(outputs->file, O_RDWR | O_APPEND | O_CREAT, 0777);
//		if (new_fd < 0)
//		{
//			print_error();
//			return (-1);
//		}
//		tmp_fd = dup2(new_fd, 1);
//		if (tmp_fd < 0)
//		{
//			print_error();
//			close(new_fd);
//			return (-1);
//		}
//		outputs = outputs->next;
//	}
//	return (new_fd);
//}

int		dup_pipes(t_cmd *cmd, int in, int out, int last_in, int last_out, int i)
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

int		ft_exec_nested_cmd(t_cmd *cmd, char ***env)
{
	t_cmd	*tmp;
	int		fd[2];
	int		in;
	int		out;
	int		last_in;
	int		last_out;
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
			dup_pipes(tmp, in, fd[1], i, last_in, last_out);
			open_inputs(tmp->input);
			open_outputs(tmp->output);
			if (isbuilt_in(tmp->args[0]))
				return (exec_builtin(tmp, env));
			path = command_path(tmp->args[0], *env);
			//write(2, tmp->args[0], ft_strlen(tmp->args[0]));
			if (execve(path, tmp->args, *env) == -1)
				write(2, "execve fail", ft_strlen("execve fail"));
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

int main(int argc, char **argv, char **envp)
{
 	t_cmd *cmd;
 	char *str = "echo hello | grep h";
 	char **table = ft_split(str, 32);
 	cmd = fill_command(table);
 	print_cmd(cmd);
 	char **dup_env = ft_tabdup(envp);
	write(1, "\n", 1);
 	ft_exec_nested_cmd(cmd, &dup_env);
}
