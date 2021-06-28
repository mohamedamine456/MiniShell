/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_functions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:46:58 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/28 13:50:41 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_FUNCTIONS_H
# define STRUCTS_FUNCTIONS_H
# include "../parse.h"

/*
 * cmd_functions.c prototypes
 */

void			add_back_cmd(t_cmd **cmds, t_cmd *new);
void			clear_cmds(t_cmd **cmds);
t_cmd			*last_cmd(t_cmd *cmd);
t_cmd			*new_cmd(void);
int				size_cmds(t_cmd *cmds);

/*
 * input_functions.c prototypes
 */

void			add_redirection_back(t_redirection **redirection,
					t_redirection *new);
t_redirection	*new_redirection(void);
void			clear_redirection(t_redirection **redi);

#endif
