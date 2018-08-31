#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

int	main(int ac, char **av)
{
	char *line;

	while(ft_get_next_line(0, &line))
	{
		if (ft_strcmp(line, "1234") == 0)
			return (0);
		printf("%s\n", line);
	}
	return (0);
}
