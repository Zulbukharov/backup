#include "head.h"

queen	*create(int col, int row)
{
	queen *new;

	new = malloc(sizeof(queen));
	if (!new)
		return (NULL);
	new->col = col;
	new->row = row;
	new->next = NULL;
	return (new);
}

queen	*push(int col, int row, queen *head)
{
	queen *new;
	
	new = create(col, row);
	new->next = head;
	return (new);
}

queen	*pop(queen *head)
{
	queen *temp;

	temp = head;
	head = head->next;
	free(temp);
	temp->next = NULL;
	return (head);
}

void	print(queen **head, int n)
{
	queen *cur;
	int q;
	int cr[2] = {0, 0};
	
	while (cr[0] < n)
	{
		cr[1] = 0;
		while (cr[1] < n)
		{
			q = 0;
			cur = *head;
			while (cur)
			{
				if (cur->col == cr[0] && cur->row == cr[1])
					q += 1;
				else
					q += 0;
				cur = cur->next;
			}
		if (q == 0)
			printf("O");
		else
			printf("X");
		cr[1]++;
		}
	printf("\n");
	cr[0]++;
	}
}
