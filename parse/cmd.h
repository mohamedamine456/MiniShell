/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:06:57 by eel-orch          #+#    #+#             */
/*   Updated: 2021/03/30 17:00:34 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
#define CMD_H

typedef struct		s_cmd
{
	char 			*name;
	char 			*option;
	char 			**output;
	char 			**input;
	char			**args;
	struct s_cmd	*next;
}					t_cmd;

#endif
