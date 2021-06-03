/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:33:37 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/03 18:07:02 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EXECUTION_H
# define EXECUTION_H

# include "../minishell.h"
# include "built_in/built_in.h"

int ft_exec_nested_cmd(t_cmd *cmd, char ***env);

#endif
