
#include "../minishell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

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
int		open_inputs(t_input *inputs, int fd)
{
	t_input *tmp;

	tmp = inputs;
	if (inputs == NULL)
	{
		write(fd, "no input files\n", ft_strlen("no input files\n"));
		return (0);
	}
	while (tmp)
	{
		fd = open(tmp->file, O_RDWR |  O_APPEND | O_CREAT, 0777);;
		if (fd == -1)
		{
			print_error();
			return (-1);
		}
		if (dup2(fd, 0) == -1)
		{
			print_error();
			close(fd);
			return (-1);
		}
		tmp = tmp->next;
	}
	return (1);
}

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
int	open_outputs(t_output *outputs, int fd)
{
	int	new_fd;
	int	tmp_fd;

	if (outputs == NULL)
	{
		write(fd, "no output files\n", ft_strlen("no output files\n"));
		return (0);
	}
	new_fd = 1;
	while (outputs != NULL)
	{
		if (outputs->type == SIMPLE_REDIRECTION)
			new_fd = open(outputs->file, O_RDWR | O_CREAT, 0777);
		else if (outputs->type == DOUBLE_REDIRECTION)
			new_fd = open(outputs->file, O_RDWR | O_APPEND | O_CREAT, 0777);
		if (new_fd < 0)
		{
			print_error();
			return (-1);
		}
		tmp_fd = dup2(new_fd, 1);
		if (tmp_fd < 0)
		{
			print_error();
			close(new_fd);
			return (-1);
		}
		outputs = outputs->next;
	}
	return (new_fd);
}

int		dup_pipes(t_cmd *cmd, int in, int out, int std_out, int std_in, int i)
{
	if (cmd->next != NULL)
	{
		write(2, "dup fd[1] with  std_out\n", ft_strlen("dup fd[1] with  std_out\n"));
		dup2(out, 1);
		close(out);
	}
	if (i != 0)
	{
		write(2, "dup fd[0] with std_in\n", ft_strlen("dup fd[0] with std_in\n"));
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
	int		std_in = dup(0);
	int		std_out = dup(1);
	char	*path;
	int		i;
	pid_t	pid;

	tmp = cmd;
	in = 0;
	out = 1;
	i = 0;
	pipe(fd);
	while (tmp != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			dup_pipes(tmp, fd[0], fd[1], std_in, std_out, i);
			//in = open_inputs(tmp->input, test_file);
			//out = open_outputs(tmp->output, test_file);
			path = command_path(tmp->name, *env);
			execve(path, tmp->args, *env);
			exit(0);
		}
		close(fd[1]);
		wait(NULL);
		tmp = tmp->next;
		i++;
	}
	close(fd[0]);
	// dup2(0, std_in);
	// dup2(1, std_out);
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	t_cmd *cmd;
	char **tap;

	// // test_file = open("ff", O_RDWR |O_CREAT | O_APPEND, 0777);
	// tap = ft_tabdup(envp);
	// cmd	= (t_cmd *)malloc(sizeof(t_cmd));
	// cmd->name = strdup("echo");
	// cmd->args = ft_split("echo file file" ,32);
	// //cmd->next = NULL;
	// cmd->input = NULL;
	// cmd->output = NULL;
	// cmd->option = NULL;
	// // cmd->input = (t_input *)malloc(sizeof(t_input));
	// // cmd->input->file = ft_strdup("file2");
	// // cmd->input->next = NULL;
	
	// // cmd->output = (t_output *)malloc(sizeof(t_output));
	// // cmd->output->file = ft_strdup("file");
	// // cmd->output->type = SIMPLE_REDIRECTION;
	// // cmd->output->next = NULL;
	
	// cmd->next = (t_cmd *)malloc(sizeof(t_cmd));
	// cmd->next->name = ft_strdup("grep");
	// cmd->next->args = ft_split("grep f", 32);
	// cmd->next->input = NULL;
	// cmd->next->output = NULL;
	// cmd->next->next = NULL;
	// // cmd->next->input = (t_input *)malloc(sizeof(t_input));
	// // cmd->next->input->file = ft_strdup("file3");
	// // cmd->next->input->next = NULL;
	// //cmd->next->next = NULL;
	// ft_exec_nested_cmd(cmd, &tap);
	// // close(te)
	while (1);
}