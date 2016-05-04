#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element
{
	int nombre;
	Element *suivant;
};

typedef struct Pile Pile;
struct Pile
{
	Element *premier;
};

void empiler(Pile *pile, int nvNombre);
int depiler(Pile *pile);
void afficherPile(Pile *pile);
Pile *initialiser();

int main(void)
{
	Pile *maPile = initialiser();
/*Initialiser() attribue une adresse et une autorisation d'utiliser un espace mémoire à *maPile*/

	empiler(maPile, 4);
	empiler(maPile, 8);
	empiler(maPile, 15);
	empiler(maPile, 16);
	empiler(maPile, 23);
	empiler(maPile, 42);

	printf("\nEtat de la pile :\n");
	afficherPile(maPile);

	printf("Je depile %d\n", depiler(maPile));
	printf("Je depile %d\n", depiler(maPile));

	printf("\nEtat de la pile :\n");
	afficherPile(maPile);

	return 0;
}

Pile *initialiser()
{
	Pile *pile = malloc(sizeof(*pile));
	return pile;
}

/*Empilage de la pile*/
void empiler(Pile *pile, int nvNombre)
{
	Element *nouveau = malloc(sizeof(*nouveau));
	if (pile == NULL || nouveau == NULL)
		exit(EXIT_FAILURE);

	nouveau->nombre = nvNombre;
	nouveau->suivant = pile->premier;
	pile->premier = nouveau;
}

int depiler(Pile *pile)
{
	int nombreDepile = 0;
	if(pile == NULL)
		exit(EXIT_FAILURE);

	Element *elementDepile = pile->premier;
	if(pile != NULL && pile->premier != NULL)
	{
		nombreDepile = elementDepile->nombre;
		pile->premier = elementDepile->suivant;
		free(elementDepile);
	}

	return nombreDepile;
}

void afficherPile(Pile *pile)
{
	if(pile == NULL)
		exit(EXIT_FAILURE);

	Element *actuel = pile->premier;

	while(actuel != NULL)
	{
		printf("%d\n", actuel->nombre);
		actuel = actuel->suivant;
	}

	printf("\n");
}
