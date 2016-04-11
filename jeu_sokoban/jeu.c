/*

jeu.c
------------------

Moteur du jeu



*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "constantes.h"
#include "jeu.h"

int niveauActuel = 0;

void jouer(SDL_Surface* ecran)
{
	SDL_Surface *mario[4] = {NULL};
	SDL_Surface *mur = NULL, *caisse = NULL, *caisseOK = NULL, *objectif = NULL, *marioActuel = NULL, *gagner = NULL;
	SDL_Surface *regle = NULL;
	SDL_Rect position, positionJoueur;
	SDL_Event event;

	int continuer = 1, objectifRestants = 0, i = 0, j = 0;
	int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] = {0};

	//Chargement des sprites (décors, perso ...)
	mur = IMG_Load("mur.jpg");
	caisse = IMG_Load("caisse.jpg");
	caisseOK = IMG_Load("caisse_ok.jpg");
	objectif = IMG_Load("objectif.png");
	mario[BAS] = IMG_Load("mario_bas.gif");
	mario[GAUCHE] = IMG_Load("mario_gauche.gif");
	mario[HAUT] = IMG_Load("mario_haut.gif");
	mario[DROITE] = IMG_Load("mario_droite.gif");
	regle = IMG_Load("regle.png");
	gagner = IMG_Load("gagner.png");


	marioActuel = mario[BAS];

	//Chargement du niveau
	if(!chargerNiveau(carte, niveauActuel))
		exit(EXIT_FAILURE);

	/*Recherche de la position de mario au départ*/
	for(i = 0; i < NB_BLOCS_LARGEUR; i++)
	{
		for(j = 0; j < NB_BLOCS_HAUTEUR; j++)
		{
			if(carte[i][j] == MARIO)
			{
				positionJoueur.x = i;
				positionJoueur.y = j;
				carte[i][j] = VIDE;
			}
		}
	}
	//Mise en place de l'ecran d'aide
	while(continuer)
	{
		SDL_BlitSurface(regle, NULL, ecran, &position);
		SDL_WaitEvent(&event);
		if(event.type == SDL_QUIT)
			exit(EXIT_SUCCESS);

		if(event.key.keysym.sym == SDLK_ESCAPE)
			continuer = 0;

		SDL_Flip(ecran);
	}
	SDL_FreeSurface(regle);
	continuer = 1;
	// Activation de la répétition des touches
	SDL_EnableKeyRepeat(100, 100);

	while(continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				exit(EXIT_SUCCESS);
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						continuer = 0;
						break;
					case SDLK_UP:
						marioActuel = mario[HAUT];
						deplacerJoueur(carte, &positionJoueur, HAUT);
						break;
					case SDLK_DOWN:
						marioActuel = mario[BAS];
						deplacerJoueur(carte, &positionJoueur, BAS);
						break;
					case SDLK_LEFT:
						marioActuel = mario[GAUCHE];
						deplacerJoueur(carte, &positionJoueur, GAUCHE);
						break;
					case SDLK_RIGHT:
						marioActuel = mario[DROITE];
						deplacerJoueur(carte, &positionJoueur, DROITE);
						break;
				}
				break;
		}
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		objectifRestants = 0;
		for (i = 0; i < NB_BLOCS_LARGEUR; i++)
		{
			for (j = 0; j < NB_BLOCS_HAUTEUR; j++)
			{
				position.x = i * TAILLE_BLOC;
				position.y = j * TAILLE_BLOC;
				switch(carte[i][j])
				{
					case MUR:
						SDL_BlitSurface(mur, NULL, ecran, &position);
						break;
					case CAISSE:
						SDL_BlitSurface(caisse, NULL, ecran, &position);
						break;
					case CAISSE_OK:
						SDL_BlitSurface(caisseOK, NULL, ecran, &position);
						break;
					case OBJECTIF:
						SDL_BlitSurface(objectif, NULL, ecran, &position);
						objectifRestants = 1;
						break;
				}
			}
		}

		SDL_Flip(ecran);
		position.x = positionJoueur.x * TAILLE_BLOC;
		position.y = positionJoueur.y * TAILLE_BLOC;
		SDL_BlitSurface(marioActuel, NULL, ecran, &position);
		SDL_Flip(ecran);
		
		if(!objectifRestants)
		{
			position.x = 0;
			position.y = 0;

			SDL_BlitSurface(gagner, NULL, ecran, &position);
			SDL_Flip(ecran);

			while(continuer)
			{
				SDL_WaitEvent(&event);
				if(event.type == SDL_QUIT)
					break;

				switch(event.key.keysym.sym)
				{
					case SDLK_KP1:
						niveauActuel++;
						jouer(ecran);
					break;
					case SDLK_KP2:
						continuer = 0;
					case SDLK_ESCAPE:
						continuer = 0;
					break;
				}
			}
		}
	}

	SDL_EnableKeyRepeat(0,0);
	SDL_FreeSurface(gagner);
	SDL_FreeSurface(mur);
	SDL_FreeSurface(caisse);
	SDL_FreeSurface(caisseOK);
	SDL_FreeSurface(objectif);
	for(i = 0; i  < 4; i++)
		SDL_FreeSurface(mario[i]);

}

void deplacerJoueur(int carte[][NB_BLOCS_HAUTEUR], SDL_Rect* pos, int direction)
{
	switch(direction)
	{
		case HAUT:
			if(pos->y - 1 < 0)
				break;
			if(carte[pos->x][pos->y - 1] == MUR)
				break;
			if((carte[pos->x][pos->y - 1] == CAISSE || carte[pos->x][pos->y -1] == CAISSE_OK) && (pos->y -2 < 0 || carte[pos->x][pos->y - 2] == MUR || carte[pos->x][pos->y - 2] == CAISSE || carte[pos->x][pos->y - 2] == CAISSE_OK))
				break;

			deplacerCaisse(&carte[pos->x][pos->y - 1], &carte[pos->x][pos->y - 2]);
			pos->y--;
			break;
		case DROITE:
			if(pos->x + 1 >= NB_BLOCS_LARGEUR)
				break;
			if(carte[pos->x + 1][pos->y] == MUR)
				break;
			if((carte[pos->x + 1][pos->y] == CAISSE || carte[pos->x + 1][pos->y] == CAISSE_OK) && (pos->x + 2 >= NB_BLOCS_LARGEUR || carte[pos->x + 2][pos->y] == MUR || carte[pos->x + 2][pos->y] == CAISSE || carte[pos->x + 2][pos->y] == CAISSE_OK))
				break;

			deplacerCaisse(&carte[pos->x + 1][pos->y], &carte[pos->x + 2][pos->y]);
			pos->x++;
			break;
		case GAUCHE:
			if(pos->x - 1 < 0)
				break;
			if(carte[pos->x - 1][pos->y] == MUR)
				break;
			if((carte[pos->x - 1][pos->y] == CAISSE || carte[pos->x - 1][pos->y] == CAISSE_OK) && (pos->x - 2 < 0 || carte[pos->x - 2][pos->y] == MUR || carte[pos->x - 2][pos->y] == CAISSE || carte[pos->x - 2][pos->y] == CAISSE_OK))
				break;

			deplacerCaisse(&carte[pos->x - 1][pos->y], &carte[pos->x - 2][pos->y]);
			pos->x--;
			break;
		case BAS:
			if(pos->y + 1 > NB_BLOCS_HAUTEUR)
				break;
			if(carte[pos->x][pos->y + 1] == MUR)
				break;
			if((carte[pos->x][pos->y + 1] == CAISSE || carte[pos->x][pos->y +1] == CAISSE_OK) && (pos->y +2 > NB_BLOCS_HAUTEUR || carte[pos->x][pos->y + 2] == MUR || carte[pos->x][pos->y + 2] == CAISSE || carte[pos->x][pos->y + 2] == CAISSE_OK))
				break;

			deplacerCaisse(&carte[pos->x][pos->y + 1], &carte[pos->x][pos->y + 2]);
			pos->y++;
			break;
	}
}

void deplacerCaisse(int *premiereCase, int *secondeCase)
{
	if(*premiereCase == CAISSE || *premiereCase == CAISSE_OK)
	{
		if(*secondeCase == OBJECTIF)
			*secondeCase = CAISSE_OK;
		else
			*secondeCase = CAISSE;

		if(*premiereCase == CAISSE_OK)
			*premiereCase = OBJECTIF;
		else
			*premiereCase = VIDE;
	}
}
