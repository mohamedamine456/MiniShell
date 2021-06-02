/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:10:29 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/02 18:20:17 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
int main()
{
	int file1 = open("file1", O_CREAT | O_WRONLY, 0777);	
	int file2 = open("file2", O_CREAT | O_WRONLY, 0777);
	dup2(file1, 1);
	dup2(file2, 1);
	close(file2);
	printf("hello world");
	while (1)
	{}
}
