/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_hash_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 17:12:17 by azulbukh          #+#    #+#             */
/*   Updated: 2018/05/05 22:45:01 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_ht_item
{
	char *key;
	char *value;

}				t_ht_item;

typedef struct	s_ht
{
	size_t		size;
	size_t		count;
	t_ht_item   **ht;
}				t_ht;

t_ht	*create(size_t n)
{
	t_ht *head;

	if (!(head = (t_ht*)malloc(sizeof(t_ht))))
		exit(1);
	if (!(head->ht = (t_ht_item**)malloc(n * sizeof(t_ht_item*))))
		exit(1);
	head->size = n;
	head->count = 0;
	return (head);
}

t_ht_item	*new_item(char *k, char *v)
{
	t_ht_item *new;

	if (!(new = (t_ht_item*)malloc(sizeof(t_ht_item))))
		exit(2);
	new->key = strdup(k);
	new->value = strdup(v);
	return (new);
}

int		clear(t_ht_item *item)
{
	if (!item || !(item->key) || !(item->value))
		return (0);
	free(item->key);
	free(item->value);
	return (1);
}

void	delete(t_ht **head)
{
	unsigned int q;

	q = 0;
	while (q < (*head)->count)
	{
		if (clear((*head)->ht[q]))
			q++;
		else
			break ;
	}
	free((*head)->ht);
	free(*head);
}

void	insert(t_ht *head, char *k, char *v, t_ht_item* (add)(char *, char *))
{
	(head->ht)[0] = add(k, v);
}

int		main(void)
{
	t_ht *head;

	head = create(5);
	printf("%ld\n", head->size);
	insert(head, "key", "value", &new_item);
	printf("%s\n", (head->ht)[0]->key);
	delete(&head);
	return (0);
}
