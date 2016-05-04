#include <stdio.h>
#include <stdlib.h>

typedef struct liste liste;
struct liste
{
	int valeur;
	liste* next;
};

typedef liste* llist;

llist ft_add_onset(llist first, int value);
llist ft_add_offset(llist first, int value);
void ft_show(llist first);
int ft_fill_or_void(llist first);

int main(void)
{
	llist first = NULL;

	for(int i=0; i < 10; i++)
	{
		first = ft_add_onset(first, i);
		first = ft_add_offset(first, i);
	}
	ft_show(first);
	return EXIT_SUCCESS;
}

llist ft_add_onset(llist first, int value)
{
	llist nouveau = malloc(sizeof(nouveau));
	nouveau->valeur = value;
	nouveau->next = first;

	return nouveau;
}

llist ft_add_offset(llist first, int value)
{
	llist nouveau = malloc(sizeof(nouveau));
	llist actual = first;

	nouveau->valeur = value;
	nouveau->next = NULL;

	if(first == NULL)
		return nouveau;

	while(actual != NULL)
	{
		actual = actual->next;
	}
	first = nouveau;
	return first;
}

int ft_fill_or_void(llist first)
{
	if(first == NULL)
		return 0;

	return 1;
}

void ft_show(llist first)
{
	if(!ft_fill_or_void(first))
		return;

	printf("%d->", first->valeur);
	ft_show(first->next);
}
