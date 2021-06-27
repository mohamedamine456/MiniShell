/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_namae.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:48:10 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/27 20:04:17 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_random_name()
{
	static int nb = 0;
	char *name;
	char *str_nb;
	char *str_modulo;

	nb++;
	str_nb = ft_itoa(nb);
	str_modulo = ft_itoa(nb % 3);
	name = ft_strjoin(str_nb, str_modulo);
	free(str_modulo);
	return (name);
}
