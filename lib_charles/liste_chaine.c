#include "liste_chaine.h"

llist ft_add_onset(llist first, int nvValeur)
{
	llist nouveau = malloc(sizeof(llist));

	nouveau->valeur = nvValeur;
	nouveau->next = first;

	return nouveau;
}

llist ft_add_ending(llist first, int nvValeur)
{
		llist nouveau = malloc(sizeof(nouveau));
		llist actual = first;

		nouveau->valeur = nvValeur;
		nouveau->next = NULL;
		
		if(first == NULL)
			return nouveau;
		else
		{
			while(actual->next != NULL)
			{
				actual = actual->next;
			}
			actual->next = nouveau;
			return first;
		}
}

llist ft_del_onset(llist first)
{
	if(ft_list_fill_or_void(first))
	{
		llist new = first;
	}

	return first;
}

llist ft_del_offset(llist first)
{
	llist temp = first;
	llist ptemp = first;

	if(first == NULL)
		return NULL;

	if(first->next == NULL)
		return NULL;

	while(temp != NULL)
	{
		ptemp = temp;
		temp = temp->next;
	}
	ptemp->next = NULL;
	free(temp);
	return first;
}

int ft_search_nb_occurence(int value, llist first)
{
	int i = 0;

	while(first != NULL)
	{
		if(first->value == value)
			i++;

		first = first->next;
	}
	return i;
}

int ft_list_fill_or_void(llist first)
{
	return (first == NULL)?0:1;
}

int ft_count_element(llist first)
{
	if(first == NULL)
		return 0;

	return ft_count_element(first->next)+1;
}

llist ft_search_value_list(llist first, int value)
{
	llist tmp = first;
	if(!ft_list_fill_or_void(first))
		return NULL;

	while(tmp != NULL)
	{
		if(tmp->value == value)
			return tmp;

		tmp = tmp->next;
	}

	return NULL /*Si aucune valeur correspondante n'à été trouvé*/
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
	printf("NULL");
}
