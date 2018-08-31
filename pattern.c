#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int main(int ac, char **av)
{
	int n;

	if (ac != 2)
		return (0);
	n = atoi(av[1]);
	for (int i = -n + 1; i < n; i++)
	{
		for (int j = -n + 1; j < n; j++)
		{
			printf("%d ", MAX(abs(i), abs(j)) + 1);
		}
		printf("\n");
	}
}
