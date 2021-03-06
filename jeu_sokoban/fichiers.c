#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "constantes.h"
#include "jeu.h"
#include "editeur.h"
#include "fichier.h"

int chargerNiveau(int niveau[][NB_BLOCS_HAUTEUR], int niveauActuel)
{

	char ligneFichier[NB_BLOCS_LARGEUR * NB_BLOCS_HAUTEUR + 1] = {0};
	int i = 0, j = 0;

	
	choice_level(ligneFichier, niveauActuel);

	for(i = 0; i < NB_BLOCS_LARGEUR; i++)
	{
		for(j = 0; j < NB_BLOCS_HAUTEUR; j++)
		{
			switch(ligneFichier[(i * NB_BLOCS_LARGEUR) + j])
			{
				case '0':
					niveau[j][i] = 0;
					break;
				case '1':
					niveau[j][i] = 1;
					break;
				case '2':
					niveau[j][i] = 2;
					break;
				case '3':
					niveau[j][i] = 3;
					break;
				case '4':
					niveau[j][i] = 4;
					break;
			}
		}
	}
	return 1;
}

int sauvegarderNiveau(int niveau[][NB_BLOCS_HAUTEUR])
{
	FILE *fichier = NULL;
	int i = 0, j = 0;

	fichier = fopen("niveaux.lvl", "a");
	if(fichier == NULL)
		return 0;

	for(i = 0; i < NB_BLOCS_LARGEUR; i++)
	{
		for(j = 0; j< NB_BLOCS_HAUTEUR; j++)
		{
			fprintf(fichier, "%d", niveau[j][i]);
		}
	}

	fprintf(fichier, "%c", '\n');
	fclose(fichier);
	return 1;
}

void choice_level(char *ligneFichier, int choiceLevel)
{
	FILE *fichier = NULL;
	int nb_level = 0;
	char c;
	

	fichier = fopen("niveaux.lvl", "r");
	if(fichier == NULL)
		exit(EXIT_FAILURE);

	while(c != EOF)
		{
			if(nb_level == choiceLevel)
				fgets(ligneFichier, NB_BLOCS_LARGEUR * NB_BLOCS_HAUTEUR + 1, fichier);

			c = fgetc(fichier);
			if(c == '\n')
				nb_level++;

		}
	fclose(fichier);
}
