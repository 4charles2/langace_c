#ifndef __MAIN_H_
#define __MAIN_H_
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

 Dlist *ft_init_Dlist();
 void ft_first_element(Dlist *p, int data);
 void ft_append(Dlist *p, int data);
 void ft_preappend(Dlist *p, int data);
 void ft_insert_(Dlist *p, int data, int position);
 void ft_show_(Dlist *p);
 void ft_dlist_delete(Dlist **list);
 void ft_del_first_node(Dlist *list);
 void ft_del_last_node(Dlist *list);
 void ft_del_node(Dlist *list, int data);
 void ft_del_all_node(Dlist *list, int data);
	
#endif
