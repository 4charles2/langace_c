#include <stdlib.h>
#include <stdio.h>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

int main(void)
{
	SDL_Surface *screen = NULL, *zozor = NULL;
	SDL_Rect posZozor;
	SDL_Event event;
	int continuer = 1;

	SDL_Init(SDL_INIT_VIDEO | 

	screen = SDL_SetVideoMode(408, 408, 32, SDL_HWSURFACE | SDL_FULLSCREEN | SDL_DOUBLEBUF | SDL_NOFRAME);

	zozor = IMG_Load("zozor.bmp");
	SDL_WM_SetCaption("Zozo en mouvement timing", NULL);
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
	SDL_SetColorKey(zozor, SDL_SRCCOLORKEY,SDL_MapRGB(zozor->format, 0, 0, 255));

	SDL_Flip(screen);

	/*Placement de la souris au milieu de l'écran*/
	SDL_WarpMouse(screen->w / 2, screen->h / 2);
	
	posZozor.x =  screen->w / 2 - zozor->w / 2;
	posZozor.y =  screen->h / 2 - zozor->h / 2;
	SDL_BlitSurface(zozor, NULL, screen, &posZozor);
	SDL_Flip(screen);

	while(continuer)
	{

		SDL_Delay(10);
		SDL_PollEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				continuer = 0;
				break;
		}
		if(event.key.keysym.sym == SDLK_ESCAPE)
			continuer = 0;

		posZozor.x++;
		posZozor.y++;
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
		SDL_BlitSurface(zozor, NULL, screen, &posZozor);
		SDL_Flip(screen);
		if(posZozor.x == screen->w)
		{
			posZozor.x = 0;
			posZozor.y = 0;
		}
	}
	return EXIT_SUCCESS;
}
