#include "main.h"


int main (void)
{
	Dlist *list = ft_init_Dlist();

	ft_append(list, 22);
	ft_append(list, 10);
	ft_preappend(list, 34);
	ft_append(list, 15);
	ft_preappend(list, 42);
	ft_show_(list);
	printf("Insert de 99 a la quatrieme place\n");
	ft_insert_(list, 99, 4);
	
	ft_show_(list);
	ft_del_first_node(list);
	printf("supression du premier noeu\n");
	ft_show_(list);
	ft_del_last_node(list);
	printf("supression du dernier noeu\n");
	ft_show_(list);
	ft_del_node(list, 99);
	printf("Supression de l'element qui porte la valeur 99\n");
	ft_show_(list);
	printf("Ajoute des valeur 22\n");
	ft_append(list, 22);
	ft_preappend(list, 22);
	ft_show_(list);
	ft_del_all_node(list, 22);
	ft_dlist_delete(&list);
	return EXIT_SUCCESS;
}
