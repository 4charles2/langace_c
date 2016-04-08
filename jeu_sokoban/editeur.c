/*
editeur.c
------------

Par charles Tognol, Pour le jeu du sokoban

Role : editeur de la carte du jeu
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "constantes.h"
#include "jeu.h"
#include "editeur.h"
#include "fichier.h"

void editeur(SDL_Surface* ecran)
{
	SDL_Surface *mur = NULL, *caisse = NULL, *objectif = NULL, *mario = NULL;
	SDL_Rect position;
	SDL_Event event;

	int continuer = 1, clicGaucheEnCours = 0, clicDroiteEnCours = 0;
	int objetActuel = MUR, i = 0, j = 0;
	int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] = {0};

	mur = IMG_Load("mur.jpg");
	caisse = IMG_Load("caisse.jpg");
	objectif = IMG_Load("objectif.png");
	mario = IMG_Load("mario_bas.gif");

	if(!chargerNiveau(carte))
		exit(EXIT_FAILURE);
	
	while(continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				exit(EXIT_SUCCESS);
				break;
			case SDL_MOUSEBUTTONDOWN:
				if(event.button.button == SDL_BUTTON_LEFT)
				{
					carte[event.button.x / TAILLE_BLOC][event.button.y / TAILLE_BLOC] = objetActuel;
					clicGaucheEnCours = 1;
				}
				else if(event.button.button == SDL_BUTTON_RIGHT)
				{
					carte[event.button.x / TAILLE_BLOC][event.button.y / TAILLE_BLOC] = VIDE;
					clicDroiteEnCours = 1;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				if(event.button.button == SDL_BUTTON_LEFT)
					clicGaucheEnCours = 0;
				else if(event.button.button == SDL_BUTTON_RIGHT)
					clicDroiteEnCours = 0;
				break;
			case SDL_MOUSEMOTION:
				if(clicGaucheEnCours)
					carte[event.motion.x / TAILLE_BLOC][event.motion.y / TAILLE_BLOC] = objetActuel;
				else if (clicDroiteEnCours)
					carte[event.motion.x / TAILLE_BLOC][event.motion.y / TAILLE_BLOC] = VIDE;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						continuer = 0;
						break;
					case SDLK_s:
						sauvegarderNiveau(carte);
						break;
					case SDLK_KP1:
						objetActuel = MUR;
						break;
					case SDLK_KP2:
						objetActuel = CAISSE;
						break;
					case SDLK_KP3:
						objetActuel = OBJECTIF;
						break;
					case SDLK_KP4:
						objetActuel = MARIO;
						break;
				}
				break;
		}

		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		for(i=0; i < NB_BLOCS_LARGEUR; i++)
		{
			for(j = 0; j < NB_BLOCS_HAUTEUR; j++)
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
					case OBJECTIF:
						SDL_BlitSurface(objectif, NULL, ecran, &position);
						break;
					case MARIO:
						SDL_BlitSurface(mario, NULL, ecran, &position);
				}
			}
		}
		SDL_Flip(ecran);
	}
	SDL_FreeSurface(mur);
	SDL_FreeSurface(caisse);
	SDL_FreeSurface(objectif);
	SDL_FreeSurface(mario);
}
