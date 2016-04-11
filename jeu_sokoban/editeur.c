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
	SDL_Surface *mur = NULL, *caisse = NULL, *objectif = NULL, *mario = NULL, *regle = NULL, *cursorObjet = NULL, *caisse_ok = NULL;
	SDL_Rect position, posObjetActuel;;
	SDL_Event event;

	int continuer = 1, clicGaucheEnCours = 0, clicDroiteEnCours = 0, dejaPresent = 0;
	int objetActuel = MUR, i = 0, j = 0;
	int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] = {0};

	mur = IMG_Load("mur.jpg");
	caisse = IMG_Load("caisse.jpg");
	objectif = IMG_Load("objectif.png");
	mario = IMG_Load("mario_bas.gif");
	regle = IMG_Load("regleEditeur.png");
	caisse_ok = IMG_Load("caisse_ok.jpg");
	cursorObjet = mur;

		//Mise en place de l'ecran d'aide
		position.x = 0;
		position.y = 0;
	
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
	

	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
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
					if(objetActuel == MARIO && dejaPresent == 1)
						break;

					carte[event.button.x / TAILLE_BLOC][event.button.y / TAILLE_BLOC] = objetActuel;
					clicGaucheEnCours = 1;
				}
				else if(event.button.button == SDL_BUTTON_RIGHT)
				{
					if(carte[event.button.x / TAILLE_BLOC][event.button.y / TAILLE_BLOC] == MARIO)
						dejaPresent = 0;

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

				posObjetActuel.x = event.motion.x - TAILLE_BLOC / 2;
				posObjetActuel.y = event.motion.y - TAILLE_BLOC / 2;
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
						cursorObjet = mur;
						break;
					case SDLK_KP2:
						objetActuel = CAISSE;
						cursorObjet = caisse;
						break;
					case SDLK_KP3:
						objetActuel = OBJECTIF;
						cursorObjet = objectif;
						break;
					case SDLK_KP4:
						objetActuel = MARIO;
						cursorObjet = mario;
						break;
					case SDLK_KP5:
						objetActuel = CAISSE_OK;
						cursorObjet = caisse_ok;
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
						dejaPresent = 1;
						break;
					case CAISSE_OK:
						SDL_BlitSurface(caisse_ok, NULL, ecran, &position);
						break;
				}
			}
		}
		SDL_BlitSurface(cursorObjet, NULL, ecran, &posObjetActuel);
		SDL_Flip(ecran);
	}
	SDL_FreeSurface(mur);
	SDL_FreeSurface(caisse);
	SDL_FreeSurface(objectif);
	SDL_FreeSurface(mario);
	SDL_FreeSurface(ecran);
}
