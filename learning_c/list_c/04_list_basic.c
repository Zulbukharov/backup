/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:37:33 by azulbukh          #+#    #+#             */
/*   Updated: 2018/04/17 21:22:05 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	char p;
	struct t_node *n;
}				t_list;

t_list *create(char c)
{
	t_list *q;

	q = malloc(sizeof(t_list));
	q->p = c;
	q->n = NULL;
	return (q);
}

void	push(t_list *curr, char d)
{
	t_list *cur;

	cur = create(d);
	cur->n = curr;
}

void	print(t_list **q)
{
	t_list *cur;

	cur = *q;
	while (cur)
	{
		printf("%c", cur->p);
		cur = cur->n;
	}
}

int	main(void)
{
	t_list *q;

	q = create('2');
	printf("%c", q->p);
	push(q, '3');
	push(q, '4');
	print(&q);
	return (0);
}
