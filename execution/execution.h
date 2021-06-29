/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:33:37 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/29 20:29:23 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../minishell.h"
# include "built_in/built_in.h"

int		ft_exec_nested_cmd(t_cmd *cmd, char ***env);
int		get_exit_status(int status);
int		here_doc(char *delimeter, char *file_name);

/*
 * search_command.c prototypes
 */

int		exec_commands(t_cmd *cmd, char	**envp);
int		fork_command(char *name, char **args, char **envp);
char	*command_path(char *cmd_name, char **envp);
char	**tab_paths(char **envp);
char	*check_right_path(char *cmd_name, char **paths);

/*
 * ft_exec_nested_cmd.c helpers
 */

int		dup_pipes(t_cmd *cmd, int in, int out, int i);
void	redirect_std_in_out(t_cmd *cmd, int cmd_index, int in, int *fd);

/*
 * execution errors prototypes
 */

void	command_not_found(char *str);
void	execve_error(void);

#endif
