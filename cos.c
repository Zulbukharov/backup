#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	double x = atoi(av[1]);
	double val = PI / 180.0;

	double res = cos(x * val);
	printf("[x_value_deg][%d]\n", (int)(x));
	printf("[x_value_rad][%f]\n", x * val);
	printf("[%f]\n", res);
	return (0);
}
