#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct 		s_list
{
	char 			*r;
	size_t 			size;
	struct s_list	*n;
}					t_list;

t_list	*create(char *s, int size)
{
	t_list *new;
	int i;

	i = 0;
	if (!s || !size)
		return (NULL);
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(new->r = (char*)malloc(sizeof(char) * strlen(s) + 1)))
	{
		free(new);
		new = NULL;
		return (NULL);
	}
	while (s[i])
	{
		new->r[i] = s[i];
		i++;
	}
	new->r[i] = '\0';
	new->size = size;
	new->n = NULL;
	return (new);
}

// void	push(t_list **head, char *s, int size)
// {
// 	t_list *cur;

// 	cur = *head;
// 	if (!head || !size || !s)
// 		return ;
// 	if (!cur)
// 	{
// 		cur = create(s, size);
// 		*head = cur;
// 		return ;
// 	}
// 	while (cur->n)
// 		cur = cur->n;
// 	cur->n = create(s, size);
// }

void	pop(t_list **head)
{
	t_list *cur;

	if (!head || !*head)
		return ;
	cur = *head;
	*head = cur->n;
	free(cur);
	cur = NULL;
}

int		remove_by_size(t_list **head, size_t size)
{
	t_list *cur;
	t_list *temp;
	int res;

	if (!head || !size)
		return (0); // error input
	cur = *head;
	temp = NULL;
	if (cur->size == size)
	{
		pop(head);
		return (1); // only 1 elem;
	}
	while (cur->n && cur->n->size != size)
		cur = cur->n;
	if (cur->n && cur->n->size == size)
	{
		temp = cur->n;
		cur->n = temp->n;
		free(temp);
		return (1); // success
	}
	else
		return (0);
}

void	push_to_front(t_list **head, char *s, int size)
{
	t_list *new;

	if (!head || !s || !size)
		return ;
	new = create(s, size);
	new->n = *head;
	*head = new;
}

void	print(t_list **head)
{
	t_list *cur;

	if (!head || !*head)
		return ;
	cur = *head;
	while (cur)
	{
		printf("%s :: %zu\n", cur->r, cur->size);
		cur = cur->n;
	}
}

t_list *find(t_list **head, size_t n)
{
	t_list *cur;

	cur = *head;
	if (!cur)
		return (NULL);
	while (cur)
	{
		if (cur->size == n)
			return (cur);
		cur = cur->n;
	}
	return (NULL);
}

int		main(int ac, char **av)
{
	t_list *list;
	t_list *val;
	size_t n;
	int i;

	if (ac != 4)
		return (0);
	val = NULL;
	list = NULL;
	n = (size_t)atoi(av[1]);
	while (n)
	{
		push_to_front(&list, "random", n);
		n--;
	}
	i = remove_by_size(&list, (size_t)atoi(av[3]));
	i > 0 ? printf("\033[32;1m[REMOVED]\n") : printf("\033[31;1m[ERROR]\n");   
	print(&list); // to print all list
	(find(&list, (size_t)atoi(av[2]))) ? printf("\033[32;1m[TRUE][DETECTED: %s]\n", av[2]) : printf("\033[31;1m[FALSE][:(]\n");
	return (0);
}
