/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 10:08:51 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/25 15:14:32 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_history init_history()
{
	t_history hist;

	hist.retv = 0;
	hist.fd = open_history();
	hist = read_history(hist.fd);
	return (hist);
}
