/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:33:37 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/27 20:12:42 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EXECUTION_H
# define EXECUTION_H

# include "../minishell.h"
# include "built_in/built_in.h"

int ft_exec_nested_cmd(t_cmd *cmd, char ***env);
int	get_exit_status(int status);
int	here_doc(char *delimeter, char *file_name);
#endif
