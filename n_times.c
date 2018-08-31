#include <stdio.h>
#include <stdlib.h>

void	print(int n, int z)
{
	while (z > 0)
	{
		printf("%d ", (n));
		z--;
	}
}

void	space(int t, int n)
{
	while (t > 0 && n)
	{
		printf("%d ", n);
		n--;
		t--;
	}
}

void	space_plus(int t, int co, int n)
{
	while (t > 0 && n++ < co)
	{
		printf("%d ", n);
		t--;
	}
}

void	n_times(int n)
{
	int z;
	int t;
	int co;
	int foo;

	t = 0;
	co = n;
	z = n + n - 1;
	foo = z;
	while (z >= 1)
	{
		space(t, co);
		print(n, z);
		space_plus(t, co, n);
		z -= 2;
		n--;
		printf("\n");
		t++;
	}
	n++;
	t--;
	z = 3;
	while (z <= foo)
	{
		n++;
		t--;
		space(t, co);
		print(n, z);
		space_plus(t, co, n);
		z += 2;
		printf("\n");
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	n_times(atoi(av[1]));
	return (0);
}
