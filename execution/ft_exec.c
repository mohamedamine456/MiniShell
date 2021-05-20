
#include "../minishell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>


int 	is_simple_cmd(t_cmd *cmd)
{
	return (isbuilt_in(cmd->name) && (size_cmds(cmd) == 1));
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
int		open_inputs(t_input *inputs, int test)
{
	int		fd;
	t_input *tmp;

	tmp = inputs;
	if (inputs == NULL)
	{
		return (0);
	}
	while (tmp)
	{
		fd = open(tmp->file, O_RDONLY, 00400);
		if (fd == -1)
		{
			write(1, "error", 5);
			return (-1);
		}
		if (dup2(fd, 0) == -1)
		{
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
int	open_outputs(t_output *outputs)
{
	int	new_fd;
	int	tmp_fd;

	if (outputs == NULL)
		return (0);
	while (outputs != NULL)
	{
		if (outputs->type == SIMPLE_REDIRECTION)
			new_fd = open(outputs->file, O_WRONLY | O_CREAT, 00400);
		else if (outputs->type == DOUBLE_REDIRECTION)
			new_fd = open(outputs->file, O_WRONLY | O_APPEND | O_CREAT, 00400);
		if (new_fd < 0)
			return (-1);
		tmp_fd = dup2(new_fd, 1);
		if (tmp_fd < 0)
		{
			close(new_fd);
			return (-1);
		}
		outputs = outputs->next;
	}
	return (1);
}
int		ft_exec_nested_cmd(t_cmd *cmd, char ***env)
{
	// pid_t	pid;
	// t_cmd	*tmp;
	// int		i;
	// int		std_in = dup(0);
	// int		std_out = dup(1);
	// int		**pipes;
	// int		cmd_size = size_cmds(cmd);
	// int		out = 1;
	// int		in = 0;
	// char	buf[15];
	// int inputs;
	// int	outputs;

	// tmp = cmd;
	// pipes = get_pipes(cmd);
	// i = 0;
	// int test = open("test", O_WRONLY| O_CREAT | O_APPEND);
	// char *path;
	// int fd[2];
	// int *adt = NULL;
	// while (i < cmd_size)
	// {
	// 	pipe(pipes[i]);
	// 	inputs = open_inputs(tmp->input, test);
	// 	outputs = open_outputs(tmp->output);
	// 	pid = fork();
	// 	if (pid == 0)
	// 	{
	// 		if (inputs != 1)
	// 		{
	// 			write(test, "thers is no input file\n", ft_strlen("thers is no input file\n"));
	// 			if (i != 0)
	// 				in = pipes[i - 1][0];
	// 			if (in != 0)
	// 			{
	// 				dup2(in, 0);
	// 				close(in);
	// 			}
	// 		}
	// 		if (outputs != 1)
	// 		{
	// 			write(test, "thers is no output file\n", ft_strlen("thers is no output file\n"));
	// 			out = pipes[i][1];
	// 			if (out != 1)
	// 			{
	// 				dup2(out, 1);
	// 				close(out);
	// 			}
	// 		}
	// 		path = command_path(tmp->name, *env);
	// 		write(test, tmp->name, strlen(tmp->name));
	// 		execve(path, tmp->args, *env);
	// 		if (i + 1 == cmd_size)
	// 		{
	// 			dup2(std_out, 1);
	// 			dup2(std_in, 0);
	// 		}
	// 		//close(fd[0]);
	// 		//close(fd[1]);
	// 		return (0);
	// 	}
 	// 	adt = &i;
	// 	// 		read(pipes[i - 1][0], buf, 15);
	// 	// 		write(1, buf, 15);
	// 	// 		t++;
	// 	// 	}
	// 	// }
	// 	i++;
	// 	waitpid(pid, NULL, 0);
	// 	tmp = tmp->next;
	// }
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	t_cmd *cmd;
	char **tab;

	tab = ft_tabdup(envp);
	cmd	= (t_cmd *)malloc(sizeof(t_cmd));
	cmd->name = strdup("cat");
	cmd->args = ft_split("cat" ,32);
	
	cmd->input = (t_input *)malloc(sizeof(t_input));
	cmd->input->file = ft_strdup("file2");
	cmd->input->next = NULL;
	
	cmd->output = NULL;//(t_output *)malloc(sizeof(t_output));
	// cmd->output->file = ft_strdup("file3");
	// cmd->output->type = SIMPLE_REDIRECTION;
	// cmd->output->next = NULL;
	
	cmd->next = NULL;//(t_cmd *)malloc(sizeof(t_cmd));
	// cmd->next->name = strdup("grep");
	// cmd->next->args = ft_split("grep f", 32);
	
	// cmd->next->input = (t_input *)malloc(sizeof(t_input));
	// cmd->next->input->file = ft_strdup("file3");
	// cmd->next->input->next = NULL;
	
	// cmd->next->next = NULL;
	ft_exec_nested_cmd(cmd, &tab);
}