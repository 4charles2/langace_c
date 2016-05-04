#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <fmodex/fmod.h>

#define HAUTEUR 400
#define LARGEUR 512
#define RATIO	(HAUTEUR / 255.0)
#define DELAI_RAFRAICHISSEMENT 25
#define TAILLE_SPECTRE 512

void setPixel(SDL_Surface *surface, int x, int y, Uint32 pixel);

int main()
{
	SDL_Surface *screen = NULL;
	SDL_Event event;
	int continuer = 1, hauteurBarre = 0, tempsActuel = 0, tempsPrecedent = 0, i = 0, j = 0;
	float spectre[512];

	FMOD_SYSTEM *system = NULL;
	FMOD_SOUND *musique;
	FMOD_CHANNEL *canal;
	FMOD_RESULT resultat;

	FMOD_System_Create(&system);
	FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);

	resultat = FMOD_System_CreateSound(system, "hype_home.mp3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &musique);
	if(resultat != FMOD_OK)
	{
		fprintf(stderr, "Impossible de lire le fichier mp3\n");
	}
	FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, musique, 0, NULL);
	FMOD_System_GetChannel(system, 0, &canal);

	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(LARGEUR, HAUTEUR, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Visualisation spectrale du son", NULL);
	while(continuer)
	{
		SDL_PollEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				continuer = 0;
				break;
		}
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		tempsActuel = SDL_GetTicks();
		if(tempsActuel - tempsPrecedent < DELAI_RAFRAICHISSEMENT)
		{
			SDL_Delay(DELAI_RAFRAICHISSEMENT - (tempsActuel - tempsPrecedent));
		}
		tempsPrecedent = SDL_GetTicks();

		FMOD_Channel_GetSpectrum(canal, spectre, TAILLE_SPECTRE, 0, FMOD_DSP_FFT_WINDOW_RECT);
		SDL_LockSurface(screen);

		for(i = 0; i < LARGEUR; i++)
		{
			hauteurBarre = spectre[i] * 20 * HAUTEUR;
			if(hauteurBarre > HAUTEUR)
				hauteurBarre = HAUTEUR;

			for(j = HAUTEUR - hauteurBarre; j < HAUTEUR; j++)
			{
				setPixel(screen, i, j, SDL_MapRGB(screen->format, 255 - (j / RATIO), j / RATIO, 0));
			}
		}
		SDL_UnlockSurface(screen);
		SDL_Flip(screen);
	}
	FMOD_Sound_Release(musique);
	FMOD_System_Close(system);
	FMOD_System_Release(system);

	SDL_Quit();

	return EXIT_SUCCESS;
}

void setPixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
	int bpp = surface->format->BytesPerPixel;

	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

	switch(bpp)
	{
		case 1:
			*p = pixel;
			break;
		case 2:
			*(Uint16 *)p = pixel;
			break;
		case 3:
			if(SDL_BYTEORDER == SDL_BIG_ENDIAN){
				p[0] = (pixel >> 16) & 0xff;
				p[1] = (pixel >> 8) & 0xff;
				p[2] = pixel & 0xff;
			} else {
				p[0] = pixel & 0xff;
				p[1] = (pixel >> 8) & 0xff;
				p[2] = (pixel >> 16) & 0xff;
			}
			break;
		case 4:
			*(Uint32 *)p = pixel;
			break;
	}
}
