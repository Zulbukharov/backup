#ifndef HEAD_H
# define HEAD_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct queens
{
	int col;
	int row;
	struct queens *next;
}		queen;

void	print(queen **head, int n);
queen	*push(int col, int row, queen *head);
queen	*pop(queen *head);
queen	*create(int col, int row);

#endif
