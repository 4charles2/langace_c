/*
constante.c
-----------

Par Charles Tognol, Pour le jeu du Pendu

Rôle : défini toutes les constantes du jeu
*/

#ifndef __CONSTANTE__
#define __CONSTANTE__

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
	typedef struct s_show
	{
		SDL_Surface *area[8];
		SDL_Surface *pendu[6];
		SDL_Surface *surface_font[3];
		SDL_Rect position_decor[5];
		SDL_Rect position_pendu[6];
		SDL_Rect position_font[4];
		TTF_Font *font, *font2;
		int continuer;
		char *texte[3];
		char mystery_word[30];
		char answer_word[30];
		int nb_shots;
		char character_already[20];
		int nb_gamer;
	}t_show;

#endif
