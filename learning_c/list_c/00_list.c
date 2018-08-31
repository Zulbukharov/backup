/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:12:38 by azulbukh          #+#    #+#             */
/*   Updated: 2018/03/31 18:48:13 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef	struct list
{
	int data;
	struct list *next;
}				node;

node	*create_elem(int data)
{
	node *new;

	if (!data)
		return (NULL);
	printf("sizeof node: %zu\n", sizeof(node));
	if (!(new = malloc(sizeof(node))))
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	push(node *head, int data)
{
	node *cur = head;

	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = create_elem(data);
}

void	print(node *head)
{
	node *cur = head;

	while (cur)
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	}
}

int	main(int ac, char **av)
{
	node	*head;
	node	*foo;
	int	l = atoi(av[1]);

	if (ac < 1)
		return (0);
	head = malloc(sizeof(node));
	head->data = 5;
	head->next = NULL;
	foo = create_elem(3);
	printf("%d\n", foo->data);
	while (l--)
	{
		push(foo, l);
	}
	print(foo);
	return (0);
}
