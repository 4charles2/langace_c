#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *p_next;
	/*Pointe vers l'element suivant*/
	struct node *p_prev;
	/*Pointe vers l'element precedent*/
};
typedef struct dlist
{
	size_t length;
	/*Pointe vers le premier element*/
	struct node *p_head;
	/*Pointe vers le dernier element*/
	struct node *p_tail;
}Dlist;

Dlist *dlist_new(void);
Dlist *append(Dlist *p, int data);
void ft_show_list(Dlist *p);
Dlist *ft_first_element(Dlist *p, struct node *element);
Dlist *ft_preappend(Dlist *p, int data);
Dlist *ft_dlist_insert(Dlist *p, int data, int position);

int main (void)
{
	Dlist *list = dlist_new();

	list = append(list, 10);
	list = append(list, 15);
	list = ft_preappend(list, 22);
	list = append(list, 42);
	list = ft_preappend(list, 34);
	list = ft_preappend(list, 67);
	list = ft_dlist_insert(list, 64, 4);

	ft_show_list(list);

		return EXIT_SUCCESS;
}

Dlist *ft_dlist_insert(Dlist *p, int data, int position)
{
	struct node *element = malloc(sizeof(*element));
	struct node *tmp = p->p_tail;
	int i = 1;
	element->data = data;
	if(p->p_tail == NULL)
		return ft_first_element(p, element);
	else
	{
		while(i++ < position)
		{
			if(tmp->p_next == NULL)
				return  append(p, data);

			printf("%d", i);
			tmp = tmp->p_next;
		}
		element->p_next = tmp;
		element->p_prev = tmp->p_prev;
		tmp->p_prev->p_next = element;
		tmp->p_prev = element;
	}
	return p;
}

Dlist *ft_preappend(Dlist *p, int data)
{
	struct node *element = malloc(sizeof(*element));
	element->data = data;

	if(p->p_tail == NULL)
		p = ft_first_element(p, element);
	else
	{
		element->p_prev = NULL;
		element->p_next = p->p_head;
		p->p_head = element;
	}
	p->length++;
	return p;

}

Dlist *ft_first_element(Dlist *p, struct node *element)
{
	p->p_tail = element;
	p->p_head = element;
	element->p_prev = NULL;
	return p;
}

Dlist *append(Dlist *p, int data)
{
	struct node *element = malloc(sizeof(*element));
	element->p_next = NULL;
	element->data = data;

	if(p->p_head == NULL)
		p = ft_first_element(p, element);
	else
	{
			p->p_tail->p_next =  element;
			element->p_prev = p->p_tail;
			p->p_tail = element;
			p->length++;
	}
	return p;
}

Dlist *dlist_new(void)
{
	Dlist *p_new = malloc(sizeof *p_new);
	if(p_new != NULL)
	{
		p_new->length = 0;
		p_new->p_head = NULL;
		p_new->p_tail = NULL;
	}
	return p_new;
}

void ft_show_list(Dlist *p)
{
	struct node *tmp = p->p_head;
	if(p->p_tail == NULL)
		return;

	/*printf("Nombre d'élément dans la liste : %d\n", p->length);*/
	while(tmp != NULL)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->p_next;
	}
}
