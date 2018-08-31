/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 16:42:58 by azulbukh          #+#    #+#             */
/*   Updated: 2018/04/17 19:40:04 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct t_list
{
	int		data;
	struct t_list *next;
}				list;

list	*create(int a)
{
	list *new;

	new = malloc(sizeof(list));
	if (!new)
		return (NULL);
	new->data = a;
	new->next = NULL;
	return (new);
}

void	push(list *new, int l)
{
	list *cur;

	cur = new;
	while (cur->next)
		cur = cur->next;
	cur->next = create(l);
}

void	print(list **new)
{
	list *cur = *new;

	while (cur)
	{
		printf("data: %d\n address: %p\n\n", cur->data, cur);
		cur = cur->next;
	}
}

int		main(int ac, char **av)
{
	if (ac < 1)
		return (0);
	
	int l = atoi(av[1]);
	list *new;

	new = create(0);
	while (l)
	{
		push(new, l);
		l--;
	}
	printf("address of list: %p\n\n", &new);
	print(&new);
	return (0);
}

