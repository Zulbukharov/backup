#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	printf("%d\n", dup(0));
	printf("%d\n", dup(0));
	return (0);
}
