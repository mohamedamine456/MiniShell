/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:02:02 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/02 17:58:14 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

t_builtin_vars cmd_to_builtin_vars(t_cmd *cmd, char ***envp)
{
	t_builtin_vars vars;
	int retv;

	vars.args = cmd->args;//ft_tabdup(cmd->args);	
	vars.envp = envp;
	if (cmd->option != NULL)
		vars.option = ft_strdup(cmd->option);
	vars.ft_builtin[0] = ft_echo;
	vars.ft_builtin[1] = ft_cd;
	vars.ft_builtin[2] = ft_pwd;
	vars.ft_builtin[3] = ft_unset;
	vars.ft_builtin[4] = ft_export;
	vars.ft_builtin[5] = ft_env;
	vars.ft_builtin[6] = ft_exit;
	return (vars);
}

int	exec_builtin(t_cmd *cmd, char ***env)
{
	t_builtin_vars vars;
	int				retv;

	retv = 0;
	vars = cmd_to_builtin_vars(cmd, env);	
	vars.ft_builtin[isbuilt_in(cmd->args[0]) - 20](vars, &retv);
	return (retv);
}

//int main(int argc, char *argv[], char *env[])
//{
//	char buf[5];
//	int test_file = open("test_file", O_RDWR | O_CREAT,);
//	int std_out = dup(1);
//	if (test_file == -1)
//		exit(0);
//	dup2(test_file, 1);
//	char **envp = ft_tabdup(env);
//	t_cmd *cmd = new_cmd();
//	read(0, buf, 4);
//	buf[4] = '\0';
//	cmd->args = ft_split("echo hello_worls", 32);
//	exec_builtin(cmd, &envp);
//	dup2(std_out, 1);
//	printf("testdfsdsfdsfdf");
//}
