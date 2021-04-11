# include <stdio.h>
# include <unistd.h>

int main()
{
	if (isatty(0))
		printf("Terminal name is: %s\n", ttyname(0));
	else
		printf("Not a Terminal\n");
	return (0);
}
