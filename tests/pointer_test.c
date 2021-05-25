#include <stdio.h>
#include "../libft/libft.h"

int main()
{
	char *str1;
	char *str2;
	char *str3;

	str2 = str1;
	str1 = ft_strdup("hello world");
	printf("str1: %s\nstr2: %s\n", str1, str2);
	free(str1);
	str1 = ft_strdup("Welcome to C");
	printf("str1: %s\nstr2: %s\n", str1, str2);
	free(str1);
	while (1)
	{
	}
	return (0);
}
