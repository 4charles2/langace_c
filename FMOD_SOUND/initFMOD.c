#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <fmodex/fmod.h>

int main(void)
{
	SDL_Surface *screen = NULL, *viseur = NULL;
	SDL_Event event;
	SDL_Rect position;
	FMOD_SYSTEM *system;
	FMOD_SOUND *tir = NULL;
	FMOD_RESULT resultat;
	int continuer = 1;

	/*Initiation de FMOD pour le tir du pistolet*/
	FMOD_System_Create(&system);
	FMOD_System_Init(system, 2, FMOD_INIT_NORMAL, NULL);

	resultat = FMOD_System_CreateSound(system,"gun_shot.mp3",FMOD_CREATESAMPLE, 0, &tir);
	if(resultat != FMOD_OK)
	{
		fprintf(stderr, "Impossible de lire gun_shot.mp3");
		exit(EXIT_FAILURE);
	}
	/*Initiation de la SDL*/
	SDL_Init(SDL_INIT_VIDEO);
	SDL_ShowCursor(SDL_DISABLE);
	screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Gestion du son avec FMOD", NULL);
	viseur = IMG_Load("cible.png");

	SDL_EnableKeyRepeat(10, 10);
	while(continuer)
	{
		SDL_WaitEvent(&event);

		switch(event.type)
		{
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_MOUSEBUTTONDOWN:
				FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, tir, 0, NULL);
				break;
			case SDL_MOUSEMOTION:
				position.x = event.motion.x - (viseur->w / 2);
				position.y = event.motion.y - (viseur->h / 2);
				break;
		}
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		SDL_BlitSurface(viseur, NULL, screen, &position);
		SDL_Flip(screen);
	}

	SDL_FreeSurface(viseur);
	SDL_Quit();
	FMOD_Sound_Release(tir);
	FMOD_System_Close(system);
	FMOD_System_Release(system);

	return EXIT_SUCCESS;
}
