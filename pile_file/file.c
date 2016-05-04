#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element
{
	int nombre;
	Element *suivant;
};

typedef struct File File;
struct File
{
	Element *premier;
};

File *initialiser();
void remplirFile(File *file, int nvNombre);
void afficherFile(File *file);
void defiler(File *file);

int main(void)
{
	File *myFile = initialiser();

	remplirFile(myFile, 4);
	remplirFile(myFile, 8);
	remplirFile(myFile, 15);
	remplirFile(myFile, 16);
	remplirFile(myFile, 32);
	remplirFile(myFile, 42);

	afficherFile(myFile);

	defiler(myFile);
	defiler(myFile);

	afficherFile(myFile);

	return 0;
}

void remplirFile(File *file, int nvNombre)
{
	Element *nouveau = malloc(sizeof(*nouveau));
	nouveau->suivant = NULL;
	nouveau->nombre = nvNombre;

	if(file->premier != NULL)
	{
		Element *actuel = file->premier;

		while(actuel->suivant != NULL)
			actuel = actuel->suivant;

		actuel->suivant = nouveau;
	}
	else
	{
		file->premier = nouveau;
	}
}

void defiler(File *file)
{
	Element *element = file->premier;
	printf("\nJe defile %d\n", element->nombre);

	file->premier = element->suivant;

	free(element);
}

void afficherFile(File *file)
{
	Element *element = file->premier;
	printf("Etat de la file\n");
	while(element != NULL)
	{
		printf("%d ", element->nombre);
		element = element->suivant;
	}
}

File *initialiser()
{
	File *file = malloc(sizeof(*file));
	file->premier = NULL;

	return file;
}
