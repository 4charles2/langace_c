#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

void pause(void);

int main(int argc, char **argv)
{
	SDL_Surface *personnage = NULL;
	SDL_Surface *screen = NULL;
	SDL_Rect position_personnage;

	if(SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		fprintf(stderr, "Erreur initialisation %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	SDL_WM_SetCaption("Mon application", "The application");

	if((screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE)) == NULL)
	{
		fprintf(stderr, "Chargement surface screen impossible %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 38, 196, 236));
	/*Remplie la surface screen avec la couleur defini dans SDL_MapRGB*/

	SDL_Flip(screen);
	/*Met à jour l'écran*/


	/*creation de la deuxieme surface*/
	personnage = SDL_CreateRGBSurface(SDL_HWSURFACE, 50, 50,32, 0, 0, 0, 0);
	SDL_FillRect(personnage, NULL, SDL_MapRGB(personnage->format, 255, 255, 255));

	/*Coller la deuxieme surface sur la surface souhaiter ici la fenetre screen*/
	position_personnage.x = 295;
	position_personnage.y = 215;
	SDL_BlitSurface(personnage, NULL, screen, &position_personnage);
	/*personnage = create_area(50, 50, 32);*/

	pause();
	SDL_FreeSurface(personnage);
	SDL_Quit();
	return EXIT_SUCCESS;
}

void pause()
{
	int continuer = 1;
	SDL_Event event;

	while(continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				continuer = 0;
		}
	}

}
