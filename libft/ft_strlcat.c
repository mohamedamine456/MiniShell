/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 09:27:41 by mlachheb          #+#    #+#             */
/*   Updated: 2021/02/09 09:28:01 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	src_length;
	int		i;
	size_t	dst_length;

	src_length = ft_strlen(src);
	dst_length = ft_strlen(dst);
	i = 0;
	while (i + (int)dst_length < ((int)dstsize - 1) && src[i] != '\0')
	{
		dst[i + (int)dst_length] = src[i];
		i++;
	}
	dst[i + (int)dst_length] = '\0';
	if (dstsize < dst_length)
		return (dstsize + src_length);
	else
		return (dst_length + src_length);
}
