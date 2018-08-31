#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    return (strcmp(a, b) > 0);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return (strcmp(a, b) < 0);
}

int unique(const char *a, int len)
{
	int x, z;
	int q;

	x = 0;
	z = 0;
	q = 0;
	while (x < len)
	{
		z = x + 1;
		while (z < len && z + 1 <= len)
		{
			if (a[x] == a[z])
				break ;
			else if (z + 1 == len)
				q++;
			z++;
		}
		x++;
	}
	return (q);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b)
{
	printf("[%d][%s] [%d][%s]\n", unique(a, strlen(a)), a,  unique(b, strlen(b)), b);
	if (lexicographic_sort(a, b) &&  unique(a, strlen(a)) == unique(b, strlen(b)))
		return (1);
	else
		return (unique(a, strlen(a)) > unique(b, strlen(b)));
}

/*

int sort_by_length(const char* a, const char* b) {

}
*/

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int x;
    char *temp;
    
    x = 0;
    while (x < len && x + 1 < len)
    {
        if (cmp_func(arr[x], arr[x + 1]))
        {
            temp = arr[x];
            arr[x] = arr[x + 1];
            arr[x + 1] = temp;
            x = 0;
        }
        else
            x++;
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
	printf("\n");    
	for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
/*
    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");
*/
    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
    return (0);
   }
