#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <limits.h>
#include <unistd.h>

int list(char *dir)
{
    struct dirent   *dirp;
    DIR		    *dp;

    if ((dp = opendir(dir)) == NULL)
    {
	printf("cant open %s", dir);
	return (-1);
    }
    while ((dirp = readdir(dp)) != NULL)
	printf("%s ", dirp->d_name);
    printf("\n");
    return (0);
}

int	main(int argc, char *argv[])
{
    char	    *buf;
    int		    index;

    index = 1;
    if (argc == 1)
    {
	buf = malloc(sizeof(char) * PATH_MAX);
	getcwd(buf, PATH_MAX);
	list(buf);
	free(buf);
    }
    else
	while (index < argc)
	{
	    list(argv[index]);
	    index++;
	}
    exit(0);
}

