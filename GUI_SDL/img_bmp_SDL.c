#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

void pause(void);

int main(int argc, char **argv)
{
	SDL_Surface *personnage = NULL;
	SDL_Surface *screen = NULL;
	SDL_Surface *img_background = NULL;
	SDL_Rect position_personnage, position;
	int i = 0;

	if(SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		fprintf(stderr, "Erreur initialisation %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	/*Defini le titre de la fenetre et de l'icone*/
	SDL_WM_SetCaption("Mon application", "The application");

	if((screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE)) == NULL)
	{
		fprintf(stderr, "Chargement surface screen impossible %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 38, 196, 236));
	/*Remplie la surface screen avec la couleur defini dans SDL_MapRGB*/

	/*Creation d'une image de fond */
	img_background = SDL_LoadBMP("pack_images_sdz/lac_en_montagne.bmp");
	position.x = 0;
	position.y = 0;
	SDL_BlitSurface(img_background, NULL, screen, &position);

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
	/*Je libere les surface creer*/
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
