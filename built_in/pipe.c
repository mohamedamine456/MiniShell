/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:22:16 by eel-orch          #+#    #+#             */
/*   Updated: 2021/04/18 17:28:59 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// C program to illustrate
// pipe system call in C
#include <stdio.h>
#include <unistd.h>
#define MSGSIZE 40
char* msg1 = "hello, world #1 hello, world #111 hello4";
char* msg2 = "hello, world #1 hello, world #112 hello4";
char* msg3 = "hello, world #1 hello, world #113 hello4";

int main()
{
	char inbuf[MSGSIZE];
	int p[2], i;

	if (pipe(p) < 0)
		exit(1);

	/* continued */
	/* write pipe */

	write(p[1], msg1, MSGSIZE);
	write(p[1], msg2, MSGSIZE);
	write(p[1], msg3, MSGSIZE);

	for (i = 0; i < 3; i++) {
		/* read pipe */
		read(p[0], inbuf, MSGSIZE);
		printf("% s\n", inbuf);
	}
	return 0;
}

