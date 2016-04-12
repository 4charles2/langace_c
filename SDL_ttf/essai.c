#include <stdio.h>
#include <stdlib.h>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

int main(void)
{
	SDL_Surface *screen = NULL, *text_surface = NULL, *fond = NULL;
	SDL_Event event;
	SDL_Rect pos;
	TTF_Font *my_font;
	SDL_Color color = {0,0,0,0};
	int continuer = 1;

	SDL_Init(SDL_INIT_VIDEO);

	screen = SDL_SetVideoMode(770, 386, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);

	fond = IMG_Load("moraira.jpg");
	/*Initialise TTF et renvoie -1 en cas d'erruer d'initialisation*/
	if(TTF_Init() == -1)
	{
		fprintf(stderr, "erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}

	my_font = TTF_OpenFont("alphawood.ttf", 66);

	text_surface = TTF_RenderText_Blended(my_font, "Hello !",color);


	while(continuer)
	{
		SDL_WaitEvent(&event);

		if(event.type == SDL_QUIT)
			continuer = 0;

		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

		pos.x = 0;
		pos.y = 0;
		SDL_BlitSurface(fond, NULL, screen, &pos);
		pos.x =460;
		pos.y = 20;
		SDL_BlitSurface(text_surface, NULL, screen,&pos);
		SDL_Flip(screen);
	}

	TTF_CloseFont(my_font);
	SDL_FreeSurface(text_surface);
	TTF_Quit();
	return(EXIT_SUCCESS);
}
