#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *p_next;
	struct Node *p_prev;
};
typedef struct Dlist
{
	size_t length;
	struct Node *p_head;
	struct Node *p_tail;
}Dlist;

static Dlist *ft_init_Dlist();
static Dlist *ft_first_element(Dlist *p, int data);
static Dlist *ft_append(Dlist *p, int data);
static Dlist *ft_preappend(Dlist *p, int data);
static Dlist *ft_insert_(Dlist *p, int data, int position);
static void ft_show_(Dlist *p);
static void ft_dlist_delete(Dlist **list);
static Dlist *ft_del_first_node(Dlist *list);
static Dlist *ft_del_last_node(Dlist *list);
static Dlist *ft_del_node(Dlist *list, int data);

int main (void)
{
	Dlist *list = ft_init_Dlist();

	list = ft_append(list, 22);
	list = ft_append(list, 10);
	list = ft_preappend(list, 34);
	list = ft_append(list, 15);
	list = ft_preappend(list, 42);
	ft_show_(list);
	printf("\nInsert de 99 a la quatrieme place\n");
	list = ft_insert_(list, 99, 4);
	
	ft_show_(list);
	list = ft_del_first_node(list);
	ft_show_(list);
	list = ft_del_last_node(list);
	ft_show_(list);
	list = ft_del_node(list, 99);
	printf("Supression de l'element qui porte la valeur 99\n");
	ft_show_(list);
	ft_dlist_delete(&list);
		return EXIT_SUCCESS;
}

static Dlist *ft_del_node(Dlist *list, int data)
{
	struct Node *tmp = list->p_head;
	if(tmp->data == data)
		list = ft_del_first_node(list);
	else
	{
		while(tmp != NULL && tmp->data != data)
			tmp = tmp->p_next;

		if(tmp->data == data && tmp->p_next == NULL)
			list = ft_del_last_node(list);
		else
		{
			tmp->p_prev->p_next = tmp->p_next;
			tmp->p_next->p_prev = tmp->p_prev;
			list->length--;
			free(tmp);
		}
	}
	return list;
}

static Dlist *ft_del_last_node(Dlist *list)
{
	struct Node *element = list->p_tail;
	list->p_tail = element->p_prev;
	element->p_prev->p_next = NULL;
	free(element), element = NULL;
	list->length--;
	printf("Supression du dernier noeud\n");
	return list;
}
static Dlist *ft_del_first_node(Dlist *list)
{
	struct Node *element = list->p_head;
	list->p_head = element->p_next;
	element->p_next->p_prev = NULL;
	free(element), element = NULL;
	list->length--;
	printf("supression du premier noeud\n");
	return list;
}

static void ft_dlist_delete(Dlist **list)
{
	if(*list != NULL)
	{
		struct Node *tmp = (*list)->p_head;
		while(tmp != NULL)
		{
			struct Node *del = tmp;
			tmp = tmp->p_next;
			free(del);
		}
		free(*list), list = NULL;
	}
}

static Dlist *ft_insert_(Dlist *p, int data, int position)
{
	if(p->p_head == NULL)
		p = ft_first_element(p, data);
	else
	{
		struct Node *new_node = malloc(sizeof(*new_node));
		struct Node *tmp = p->p_head;
		int i = 1;
		new_node->data = data;
		while(i++ < position && tmp != NULL)
			tmp = tmp->p_next;

		if(tmp == NULL)
			p = ft_append(p, data);
		else if(tmp->p_prev == NULL)
			p = ft_preappend(p, data);
		else
		{
			new_node->p_next = tmp;
			new_node->p_prev = tmp->p_prev;
			tmp->p_prev->p_next = new_node;
			tmp->p_prev = new_node;
		}
	}
	p->length++;
	return p;
}

static Dlist *ft_preappend(Dlist *p, int data)
{
	if(p->p_head == NULL)
		p = ft_first_element(p, data);
	else
	{
		struct Node *new_node = malloc(sizeof(*new_node));
		new_node->data = data;
		new_node->p_next = p->p_head;
		new_node->p_prev = NULL;
		p->p_head = new_node;
	}
	p->length++;
	return p;
}

static Dlist *ft_append(Dlist *p, int data)
{
	if(p->p_head == NULL)
		p = ft_first_element(p, data);
	else
	{
		struct Node *new_node = malloc(sizeof(*new_node));
		new_node->data = data;
		new_node->p_prev = p->p_tail;
		new_node->p_next = NULL;
		p->p_tail->p_next = new_node;
		p->p_tail = new_node;
	}
	p->length++;
	return p;
}

static Dlist *ft_first_element(Dlist *p, int data)
{
	struct Node *new_node = malloc(sizeof(*new_node));
	new_node->data = data;
	new_node->p_next = NULL;
	new_node->p_prev = NULL;
	p->p_tail = new_node;
	p->p_head = new_node;
	return p;
}

static void ft_show_(Dlist *p)
{
	struct Node *tmp = p->p_head;
	while(tmp != NULL)
	{
		printf("%d->",tmp->data);
		tmp = tmp->p_next;
	}
	printf("La taille de la liste : %zd\n", p->length);
}

Dlist *ft_init_Dlist()
{
	Dlist *list = malloc(sizeof(*list));
	list->length = 0;
	list->p_head = NULL;
	list->p_tail = NULL;
	return list;
}
