/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 20:24:26 by azulbukh          #+#    #+#             */
/*   Updated: 2018/04/04 19:49:42 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct queens
{
	int col;
	int row;
	struct queens *next;
}				queen;

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
	head = temp->next;
	free(temp);
	return (head);
}

int		isSafe(queen *head)
{
	int r;
	int c;
	queen *cur;

	cur = head->next;
	while (cur)
	{
		r = cur->row;
		c = cur->col;
		printf("---------------------HEAD VALUES------------%d------------%d-\n", head->col, head->row);
		if ((r == head->row || c == head->col || abs(r - head->row) == abs(c - head->col)) && head->next != cur->next)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int		place_queen(int col, int n, queen **head)
{
	int row;

	row = 0;
	if (col >= n)
		return (1);
	while (row < n)
	{
		*head = push(col, row, *head);
		printf("---------------------PLACING QUEEN----------%d------------%d\n", col, row);
		if (isSafe(*head) == 1 && place_queen(col + 1, n, head) == 1)
			return (1);
		else
			*head =	pop(*head);
		row++;
	}
	return (0);
}

void	print(queen **head, int n)
{
	queen *cur;
	int c = n;
	int cr[2] = {0, 0};

	queen *t;

	t = *head;
	while (t)
	{
		printf("%d :: %d\n", t->row, t->col);
		t = t->next;
	}
	while (cr[1] < n)
	{
		cr[0] = 0;
		while (cr[0] < n)
		{
			c = 0;
			cur = *head;
			while (cur)
			{
				if (cur->col != cr[0] && cur->row != cr[1])
					c += 0;
				else if (cur->col == cr[0] && cur->row == cr[1])
			   		c += 1;
				cur = cur->next;
			}
			if (c == 0)
				printf(".");
			else
				printf("X");
			cr[0] += 1;
		}
		printf("\n");
		cr[1] += 1;
	}
}

queen   *n_queens(int n)
{
	queen       *queens;

	queens = NULL;
	printf("Before if in n_queens\n");
	if (place_queen(0, n, &queens) == 1)
		return (queens);
	return (0);
}

int		main(int ac, char **av)
{
	queen *res;

	if (ac < 1)
		return (0);
	res = n_queens(atoi(av[1]));
	if (res == 0)
	{
		printf("0000");
		return (0);
	}
	print(&res, atoi(av[1]));
	return (0);
}
