#include <stdio.h>
#include <string.h>

int	main(void)
{
	char buff[20];
	for(int i = 0; i < 54; i++)
	{
		memcpy(&buff[i], "H", 1);
	}
	return (0);
}
