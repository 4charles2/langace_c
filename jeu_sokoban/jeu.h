#ifndef __JEU__
#define __JEU__
#include <SDL/SDL.h>
#include "constantes.h"
	void jouer(SDL_Surface* ecran);
	void deplacerJoueur(int carte[][NB_BLOCS_HAUTEUR], SDL_Rect* pos, int direction);
	void deplacerCaisse(int *premiereCase, int *secondeCase);
#endif
