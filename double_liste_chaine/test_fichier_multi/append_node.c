#include "main.h"

 void ft_insert_(Dlist *p, int data, int position)
{
	if(p->p_head == NULL)
		ft_first_element(p, data);
	else
	{
		struct Node *new_node = malloc(sizeof(*new_node));
		struct Node *tmp = p->p_head;
		int i = 1;
		new_node->data = data;
		while(i++ < position && tmp != NULL)
			tmp = tmp->p_next;

		if(tmp == NULL)
			ft_append(p, data);
		else if(tmp->p_prev == NULL)
			ft_preappend(p, data);
		else
		{
			new_node->p_next = tmp;
			new_node->p_prev = tmp->p_prev;
			tmp->p_prev->p_next = new_node;
			tmp->p_prev = new_node;
		}
	}
	p->length++;
}

 void ft_preappend(Dlist *p, int data)
{
	if(p->p_head == NULL)
		ft_first_element(p, data);
	else
	{
		struct Node *new_node = malloc(sizeof(*new_node));
		new_node->data = data;
		new_node->p_next = p->p_head;
		new_node->p_prev = NULL;
		p->p_head = new_node;
	}
	p->length++;
}

 void ft_append(Dlist *p, int data)
{
	if(p->p_head == NULL)
		ft_first_element(p, data);
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
}

 void ft_first_element(Dlist *p, int data)
{
	struct Node *new_node = malloc(sizeof(*new_node));
	new_node->data = data;
	new_node->p_next = NULL;
	new_node->p_prev = NULL;
	p->p_tail = new_node;
	p->p_head = new_node;
}
