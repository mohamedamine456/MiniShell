#include "built_in.h"

int isbuilt_in(char *cmd)
{
    int i;

    i = -1;
    if ((i = ft_strcmp(cmd, "echo")) == 0)
	return (O_ECHO);
    else if ((i = ft_strcmp(cmd, "export")) == 0)
	return (O_EXPORT);
    else if ((i = ft_strcmp(cmd, "env")) == 0)
	return (O_ENV);
    else if ((i = ft_strcmp(cmd, "exit")) == 0)
	return (O_EXIT);
    else if ((i = ft_strcmp(cmd, "cd")) == 0)
	return (O_CD);
    else if ((i = ft_strcmp(cmd, "unset")) == 0)
	return (O_UNSET);
    else if ((i = ft_strcmp(cmd, "pwd")) == 0)
	return (O_PWD); 
    return (-1);
}

int main()
{
    char *unset = "unset";
    int i;

    i = isbuilt_in(unset);
    if (i == O_UNSET)
	printf("true story");
}
