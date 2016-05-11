#include "main.h"

void ft_show_(Dlist *p)
{
	struct Node *tmp = p->p_head;
	while(tmp != NULL)
	{
		printf("%d > ",tmp->data);
		tmp = tmp->p_next;
	}
	printf("NULL Taille de la liste : %zd\n", p->length);
}

Dlist *ft_init_Dlist()
{
	Dlist *list = malloc(sizeof(*list));
	list->length = 0;
	list->p_head = NULL;
	list->p_tail = NULL;
	return list;
}
