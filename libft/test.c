#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void add_env(char ***env, char *new)
{
	char **new_env;
	int i = 0;
	new_env = ft_jointabstr(*env, new);
	*env = new_env;
}

//int main()
//{
//	char **env = ft_split("en1=1 env2=2", 32);
//	add_env(&env, "env3=3");
//	int i = 0;
//	while (env[i])
//	{
//		printf("new_env[i] == %s", env[i]);
//		i++;
//	}
//}
