#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int find_nth_term(int n, int a, int b, int c) {
	int x; 
	x = 0;
	if (n <= 3)
	{
		if (n == a)
			x = a;
		else if (n == b)
			x = b;
		else if (n == c)
			x = c;
	}
	else if (n > 3)
	{
		for (int z = 1; z <= 3; z++)
			x += find_nth_term(n - z, a, b, c);
	}
	return (x);
}

int main() {
    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    printf("%d %d %d %d\n", n, a, b, c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans); 
    return 0;
}
