/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_namae.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:48:10 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/28 16:29:33 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_random_name(void)
{
	static int	nb = 0;
	char		*name;
	char		*str_nb;
	char		*str_modulo;
	char		*tmp;

	nb++;
	str_nb = ft_itoa(nb);
	str_modulo = ft_itoa(nb % 3);
	tmp = ft_strdup("/tmp/");
	tmp = ft_strjoin(tmp, str_nb);
	name = ft_strjoin(tmp, str_modulo);
	free(str_nb);
	free(str_modulo);
	return (name);
}
