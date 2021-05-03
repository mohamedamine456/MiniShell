/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:02:02 by eel-orch          #+#    #+#             */
/*   Updated: 2021/05/03 13:08:49 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

t_builtin_vars cmd_to_builtin_vars(t_cmd *cmd, char ***envp)
{
	t_builtin_vars vars;
	int retv;

	vars.args = ft_tabdup(cmd->args);
	vars.envp = envp;
	//vars.option = ft_strdup(cmd->option);
	vars.ft_builtin[0] = ft_echo;
	vars.ft_builtin[1] = ft_cd;
	vars.ft_builtin[2] = ft_pwd;
	vars.ft_builtin[3] = ft_unset;
	vars.ft_builtin[4] = ft_export;
	vars.ft_builtin[5] = ft_env;
	vars.ft_builtin[6] = ft_exit;
	vars.ft_builtin[isbuilt_in(cmd->name - 20)](vars, &retv);

	return (vars);
}

int	exec_builtin(t_cmd *cmd, char ***env)
{
	t_builtin_vars vars;
	int				*retv;

	retv = 0;
	vars = cmd_to_builtin_vars(cmd, env);
	return (0);
}

int main(int argc, char *argv[], char *env[])
{
	t_cmd cmd;
	cmd.name = ft_strdup("echo");
	cmd.args = ft_split("okk okk", 32);
	exec_builtin(&cmd, &env);
	return (0);
}
