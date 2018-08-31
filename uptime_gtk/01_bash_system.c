#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void) 
{
	system("uptime | cut -d ' ' -f 2");	
	return (0);
}
