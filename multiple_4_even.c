#include <stdio.h>

/*
 * Доказательство того, что результат умножения на четное число
 * является четным числом
*/

int	main(void)
{
	int n;
	int even = 0;
	int odd = 0;
	int even_mult;

	even_mult = 2;
	while (even_mult < 1000)
	{
		n = 0;
		while (++n < 1000)
		{
			if (((n * even_mult) % 2) != 0)
				odd++;
			else
				even++;
		}
		even_mult += 2;
	}
	printf("[odd][%d]\n[even][%d]\n", odd, even);
	return (0);
}
