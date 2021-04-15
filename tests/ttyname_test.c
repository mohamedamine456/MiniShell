# include <stdio.h>
# include <unistd.h>

int main()
{
	char	*name;

	name = ttyname(0);
	printf("The Terminal name is: %s\n", name);
	return (0);
}
