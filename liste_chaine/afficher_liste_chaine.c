#include <stdio.h>
#include <stdlib.h>

typedef struct liste liste;
struct liste
{
	int valeur;
	liste* next;
};

typedef liste* llist;

llist ft_add_onset(llist first, int nvValeur);
llist ft_add_ending(llist first, int nvValeur);
llist ft_del_onset(llist first);
llist ft_del_offset(llist first);
llist ft_del(llist first, int value);
llist ft_search_value_list(llist first, int value);
llist ft_search_n_element(llist first, int num_element);
int ft_search_nb_occurence(int value, llist first);
int ft_count_element(llist first);
int ft_list_fill_or_void(llist first);
void ft_show_liste(llist fisrt);

int main(void)
{
	llist first = NULL;
	llist my_search = NULL;
	int nb_valeur = 0;

	if(ft_list_fill_or_void(first))
		printf("liste rempli");
	else
		printf("liste vide\n");
	
	for(int i = 1; i <= 10; i++)
	{
		first = ft_add_onset(first, i);
		first = ft_add_ending(first, i);
		if(ft_list_fill_or_void(first))
		{
			printf("liste rempli");
			ft_show_liste(first);
		}
		else
			printf("liste vide");

	}

	nb_valeur = ft_count_element(first);
	printf("%d\n", nb_valeur);

	if(ft_list_fill_or_void(first))
	{
		my_search = ft_search_n_element(first, 3);
		ft_show_liste(my_search);
		first = ft_del_onset(first);
		first = ft_del_offset(first);
		ft_show_liste(first);
	}

	/*rechercher un element qui a la valeur 7 dans cet exemple*/
	if(ft_list_fill_or_void(first))
	{
		/*Cherche le nombre d'occurence qui ont dans cette exemple la valeur 5*/
		nb_valeur = ft_search_nb_occurence(5, first);
		printf("%d\n", nb_valeur);
		my_search = ft_search_value_list(first, 7);
		ft_show_liste(my_search);
		my_search = ft_search_value_list(my_search, 8);
		ft_show_liste(my_search);
	}
	ft_show_liste(first);
	my_search = ft_del(first, 1);
	ft_show_liste(my_search);
	return EXIT_SUCCESS;
}

int ft_count_element(llist first)
{
	if(first == NULL)
		return 0;

	return ft_count_element(first->next)+1;
}

llist ft_search_n_element(llist first, int num_element)
{
	while(num_element)
	{
		first = first->next;
		num_element--;
	}
	return first;
}

int ft_search_nb_occurence(int value, llist first)
{
	int i = 0;

	while(first != NULL)
	{
		if(first->valeur == value)
			i++;

		first = first->next;
	}
	return i;
}

llist ft_search_value_list(llist first, int value)
{
	llist temp = first;

	while(temp != NULL)
	{
		if(temp->valeur == value)
			return temp;

		temp = temp->next;
	}

	return NULL;
}

llist ft_del(llist first, int value)
{
	if(first == NULL)
		return NULL;

	if(first->valeur == value)
	{
		llist tmp = first->next;
		free(first);
		tmp = ft_del(tmp, value);
		return tmp;
	}
	else
	{
		first->next = ft_del(first->next, value);
		return first;
	}
}

llist ft_del_offset(llist first)
{
	llist temp = first;
	llist ptemp = first;

	if(temp == NULL)
		return NULL;

	if(temp->next == NULL)
	{
		free(first);
		return NULL;
	}

	while(temp->next != NULL)
	{
		ptemp = temp;
		temp = temp->next;
	}
	ptemp->next = NULL;
	free(temp);
	return first;
}

llist ft_del_onset(llist first)
{
	llist temp = first->next;

	free(first);

	return temp;
}

llist ft_add_onset(llist first, int nvValeur)
{
	llist nouveau = malloc(sizeof(llist));

	nouveau->valeur = nvValeur;
	nouveau->next = first;

	return nouveau;
}

int ft_list_fill_or_void(llist first)
{
	return (first == NULL)?0:1;
}

llist ft_add_ending(llist first, int nvValeur)
{
	llist nouveau = malloc(sizeof(nouveau));
	llist actual= first;

	nouveau->valeur = nvValeur;
	nouveau->next = NULL;

	if(first == NULL)
		return nouveau;

	while(actual->next != NULL)
	{
		actual = actual->next;
	}
	actual->next = nouveau;
	return first;

}

void ft_show_liste(llist first)
{
	liste *actual = first;
	if(first == NULL)
		exit(EXIT_FAILURE);

	while(actual != NULL)
	{
		printf("%d->", actual->valeur);
		actual = actual->next;
	}
	printf("NULL\n");
}
