#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

#define RED "\x1B[31m"

typedef struct s_time
{
	int	seconds;
	int	minutes;
}		t_time;

char	*ft_lower(char *s)
{
	char *start;

	start = s;
	if (!s || !*s)
		return (NULL);
	while (*s)
	{
		if (*s >= 65 && *s <= 90)
			*s += 32;
		s++;
	}
	return (start);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (strlen(s1) != strlen(s2))
		return (0);
	while (s1 && s2 && *s1 && *s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return (0);
	}
	return (1);
}

void	show_time()
{
	time_t	seconds;
	t_time	time_c;

	time(&seconds);
	time_c.seconds = seconds % 60;
	time_c.minutes = (seconds % 3600) / 60;
	printf("time: [%d]m:[%d]s\n", time_c.minutes, time_c.seconds);
	exit(0);
}

void	show_natural()
{
	wint_t *nat = "\tНатура́льные чи́сла — числа, возникающие естественным\nобразом при счёте (например, 1, 2, 3, 4, 5, 6, 7, 8).\nПоследовательность всех натуральных чисел, расположенных\nв порядке возрастания, называется натуральным рядом\n";
	printf("%lc", nat);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("%sUsage: helper [math]\n", RED);
		return (0);
	}
	setlocale(LC_ALL, "");
	if (ft_strcmp(ft_lower(av[1]), "math"))
		show_time();
	/*
	else if (ft_strcmp(ft_lower(av[1]), "rational"))
		show_rational();
	else if (ft_strcmp(ft_lower(av[1]), "irrational"))
		show_irrational();
	*/
	if (ft_strcmp(ft_lower(av[1]), "natural"))
		show_natural();
	//else if (ft_strcmp(ft_lower(av[1]), "integer"))
	//	show_integer();
	return (0);
}
