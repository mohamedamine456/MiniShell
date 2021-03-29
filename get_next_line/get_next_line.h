/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:36:22 by mlachheb          #+#    #+#             */
/*   Updated: 2020/10/29 17:36:27 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "../libft/libft.h"
# define BUFFER_SIZE 10

char	*ft_resize(char *s1, char *s2);
int		check_end_line(char *str);
int		make_line(char **str, char **grd);
int		get_next_line(int fd, char **line);

#endif
