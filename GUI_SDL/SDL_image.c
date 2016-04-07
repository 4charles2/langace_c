#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void pause(void);

int main(int argc, char **argv)
{
	SDL_Surface *personnage = NULL;
	SDL_Surface *screen = NULL;
	SDL_Surface *img_background = NULL;
	SDL_Surface *fir = NULL;
	SDL_Rect position_personnage, position_background, position_fir;
	int i = 0;

	if(SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		fprintf(stderr, "Erreur initialisation %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	/*création d'un icone */
	SDL_WM_SetIcon(SDL_LoadBMP("pack_images_sdz/sdl_icone.bmp"), NULL);

	/*Defini le titre de la fenetre et de l'icone*/
	SDL_WM_SetCaption("Mon application", "The application");

	if((screen = SDL_SetVideoMode(806, 606, 32, SDL_HWSURFACE)) == NULL)
	{
		fprintf(stderr, "Chargement surface screen impossible %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	/*Creation d'une image de fond avec BMP*/
	img_background = SDL_LoadBMP("pack_images_sdz/lac_en_montagne.bmp");
	position_background.x = 3;
	position_background.y = 3;
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 38, 196, 236));
	/*Remplie la surface screen avec la couleur defini dans SDL_MapRGB*/

	SDL_BlitSurface(img_background, NULL, screen, &position_background);

	SDL_Flip(screen);
	/*Met à jour l'écran*/

	/*Creation d'une image pour surface */
	position_fir.x = 650;
	position_fir.y = 260;
	fir = IMG_Load("pack_images_sdz/sapin.png");
	SDL_SetAlpha(fir, SDL_SRCALPHA, 122);
	SDL_BlitSurface(fir, NULL, screen, &position_fir);
	SDL_Flip(screen);

	/*creation de la deuxieme surface*/
	personnage = SDL_LoadBMP("pack_images_sdz/zozor.bmp");
	/*Indique la transparence d'une couleur dans cette exemple la couleur bleu du fond de zozor*/
	SDL_SetColorKey(personnage, SDL_SRCCOLORKEY, SDL_MapRGB(personnage->format, 0, 0, 255));
	/*Creation de la transparence alpha du logo*/
	SDL_SetAlpha(personnage, SDL_SRCALPHA, 180);

	/*Coller la deuxieme surface sur la surface souhaiter ici la fenetre screen*/
	position_personnage.x = 485;
	position_personnage.y = 260;
	SDL_BlitSurface(personnage, NULL, screen, &position_personnage);
	/*personnage = create_area(50, 50, 32);*/
	SDL_Flip(screen);

	pause();
	/*Je libere les surface creer*/
	SDL_FreeSurface(fir);
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
