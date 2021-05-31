/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:36:44 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/31 18:47:02 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_number_length(long number)
{
	int len;

	len = 0;
	while (number > 9)
	{
		number /= 10;
		len++;
	}
	return (len + 1);
}

char	*ft_itoa(long number)
{
	char	*str;
	int		len;
	int		i;
	int		m;

	len = ft_number_length(number);
	str = (char *)malloc(len + 1);
	i = len - 1;
	while (number > 9)
	{
		m = number % 10;
		number /= 10;
		str[i] = m + 48;
		i--;
	}
	str[i] = number + 48;
	str[len] = '\0';
	return (str);
}
