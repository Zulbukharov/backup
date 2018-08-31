#include "head.h"

queen	*nQueen(int n)
{
	queen *head;

	head = NULL;
	if ((place(n, 0, &head)) == 1)
		return (head);
	return (NULL);
}

int	isSafe(queen *head)
{	
	queen *cur = head->next;
	int r;
 	int c;
	while (cur)
	{
		r = cur->row;
		c = cur->col;
		if ((r == head->row || c == head->col || abs(r - head->row) == abs(c - head->col)) && head->next != cur->next)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	place(int n, int col, queen **head)
{
	int row;

	row = 0;
	if (col >= n)
		return (1);
	while (row < n)
	{
		*head = push(col, row, *head);
		if (isSafe(*head) == 1 && place(n, col + 1, head) == 1)
			return (1);
		else
			*head = pop(*head);
		row++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	queen *res;

	if (ac < 1)
		return (0);
	res = nQueen(atoi(av[1]));
	print(&res, atoi(av[1]));	
	return (0);
}
