#include "main.h"

void ft_del_all_node(Dlist *list, int data)
{
	struct Node *tmp = list->p_head;

	while(tmp->p_next != NULL)
	{
		printf("debit");
		if(tmp->data == data)
			{
			printf("coucou");
			/*J'en suis la je pense que la chaine n'est plus disponible il va peut faloir refaire la fonction */
			ft_del_node(list, data);
			ft_show_(list);
			}
		fflush(stdout);
		printf("passage");
		tmp = tmp->p_next;
	}
}

void ft_del_node(Dlist *list, int data)
{
	struct Node *element = list->p_head;
	if(element->data == data && element->p_prev == NULL)
		ft_del_first_node(list);
	else
	{
		while(element->p_next != NULL && element->data != data)
				element = element->p_next;

		if(element->p_next == NULL && element->data == data)
			ft_del_last_node(list);
		else if (element->data == data)
		{
			element->p_next->p_prev = element->p_prev;
			element->p_prev->p_next = element->p_next;
			list->length--;
			free(element), element = NULL;
		}
	}
}

void ft_del_last_node(Dlist *list)
{
	struct Node *element = list->p_tail;
	list->p_tail = element->p_prev;
	element->p_prev->p_next = NULL;
	list->length--;
	free(element), element = NULL;
}

void ft_del_first_node(Dlist *list)
{
	struct Node *element = list->p_head;
	list->p_head = element->p_next;
	element->p_next->p_prev = NULL;
	list->length--;
	free(element), element = NULL;
}

void ft_dlist_delete(Dlist **list)
{
	if(*list != NULL)
	{
		struct Node *tmp = (*list)->p_head;
		while(tmp != NULL)
		{
			struct Node *del = tmp;
			tmp = tmp->p_next;
			free(del), del = NULL;
		}
		free(*list), list = NULL;
	}
}
