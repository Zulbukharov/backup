#include "libft/libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int	main(int ac, char **av)
{
	if (fork() == 0)
	{
		char *line;
		
		while (ft_get_next_line(0, &line))
		{
			if (ft_strcmp(line, "1234") == 0)
				exit(0);
			printf("%s", line);
		}
		//printf("child process\n");
		//system("./a.out");
		exit(0);
	}
	wait(0);
	printf("end");
	return (0);
}
