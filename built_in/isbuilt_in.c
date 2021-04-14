#include "built_in.h"

int isbuilt_in(char *cmd)
{
    int i;

    i = -1;
    if ((i = ft_strcmp(cmd, "echo")) == 0)
	return (ECHO);
    else if ((i = ft_strcmp(cmd, "export")) == 0)
	return (EXPORT);
    else if ((i = ft_strcmp(cmd, "env")) == 0)
	return (ENV);
    else if ((i = ft_strcmp(cmd, "exit")) == 0)
	return (EXIT);
    else if ((i = ft_strcmp(cmd, "cd")) == 0)
	return (CD);
    else if ((i = ft_strcmp(cmd, "unset")) == 0)
	return (UNSET);
    else if ((i = ft_strcmp(cmd, "pwd")) == 0)
	return (PWD); 
    return (-1);
}

int main()
{
    char *unset = "unset";
    int i;

    i = isbuilt_in(unset);
    if (i == UNSET)
	printf("true story");
}
