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

Pile *initialiser();
void remplirPile(Pile *pile, int nvNombre);
void depilerPile(Pile *pile);
void afficher_liste(Pile *pile);

int main(void)
{
	Pile *myPile = initialiser();
	
	remplirPile(myPile, 4);
	remplirPile(myPile, 8);
	remplirPile(myPile, 15);
	remplirPile(myPile, 16);
	remplirPile(myPile, 23);
	remplirPile(myPile, 42);

	afficher_liste(myPile);
	printf("\n");
	depilerPile(myPile);
	depilerPile(myPile);
	printf("\n");

	afficher_liste(myPile);

	/*Je depile 42 et je depile 23 Les deux derniers element de la liste*/

	return 0;
}

void depilerPile(Pile *pile)
{
	if(pile == NULL)
		exit(EXIT_FAILURE);

	Element *actuel = pile->premier;
	pile->premier = actuel->suivant;
	printf("Je depile l'element : %d\n", actuel->nombre);

	free(actuel);
}

void afficher_liste(Pile *pile)
{
	Element *actuel = pile->premier;
	if(actuel == NULL && pile == NULL)
		exit(EXIT_FAILURE);

	printf("Etat de la liste\n");
	while( actuel != NULL)
	{
		printf("%d\n", actuel->nombre);
		actuel = actuel->suivant;
	}
}

void remplirPile(Pile *pile, int nvNombre)
{

	Element *nouveau = malloc(sizeof(*nouveau));
	if(nouveau == NULL && pile == NULL)
		exit(EXIT_FAILURE);

	nouveau->nombre = nvNombre;
	nouveau->suivant = pile->premier;

	pile->premier = nouveau;
}

Pile *initialiser()
{
	Pile *pile = malloc(sizeof(*pile));
	return pile;
}
