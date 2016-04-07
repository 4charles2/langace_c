#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int main(int argc, char **argv)
{
	SDL_Surface *personnage = NULL;
	SDL_Surface *screen = NULL;
	SDL_Surface *img_background = NULL;
	SDL_Surface *fir = NULL;
	SDL_Event Evenement;
	SDL_Rect position_personnage, position_background, position_fir;
	int i = 0, continuer = 1;

	if(SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		fprintf(stderr, "Erreur initialisation %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	/*création d'un icone */
	SDL_WM_SetIcon(SDL_LoadBMP("pack_images_sdz/sdl_icone.bmp"), NULL);

	/*Defini le titre de la fenetre et de l'icone*/
	SDL_WM_SetCaption("Mon application", "The application");

	if((screen = SDL_SetVideoMode(806, 606, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
	{
		fprintf(stderr, "Chargement surface screen impossible %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	/*Creation d'une image de fond avec BMP*/
	img_background = SDL_LoadBMP("pack_images_sdz/lac_en_montagne.bmp");
	position_background.x = 3;
	position_background.y = 3;

	/*Creation d'une image pour surface */
	position_fir.x = 650;
	position_fir.y = 260;
	fir = IMG_Load("pack_images_sdz/sapin.png");
	SDL_SetAlpha(fir, SDL_SRCALPHA, 122);

	/*creation de la deuxieme surface*/
	personnage = SDL_LoadBMP("pack_images_sdz/zozor.bmp");
	/*Indique la transparence d'une couleur dans cette exemple la couleur bleu du fond de zozor*/
	SDL_SetColorKey(personnage, SDL_SRCCOLORKEY, SDL_MapRGB(personnage->format, 0, 0, 255));
	/*Creation de la transparence alpha du logo*/
	SDL_SetAlpha(personnage, SDL_SRCALPHA, 180);

	/*Coller la deuxieme surface sur la surface souhaiter ici la fenetre screen*/
	position_personnage.x = 485;
	position_personnage.y = 260;
	/*personnage = create_area(50, 50, 32);*/

	/*Activation de la répétition des touches*/
	SDL_EnableKeyRepeat(10, 100);


	while(continuer)
	{
		SDL_WaitEvent(&Evenement);

		switch(Evenement.type)
		{
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_KEYDOWN:
				switch(Evenement.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						continuer = 0;
						break;
					case SDLK_LEFT:
						position_personnage.x-=10;
						break;
					case SDLK_UP:
						position_personnage.y-=10;
						break;
					case SDLK_DOWN:
						position_personnage.y+=10;
						break;
					case SDLK_RIGHT:
						position_personnage.x+=10;
						break;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				switch(Evenement.button.button)
				{
					case SDL_BUTTON_LEFT:
						position_personnage.x = Evenement.button.x - personnage->w / 2;
						position_personnage.y = Evenement.button.y - personnage->h / 2;
						break;
					case SDL_BUTTON_RIGHT:
						position_personnage.x = Evenement.motion.x - personnage->w / 2;
						position_personnage.y = Evenement.motion.y - personnage->h / 2;
						break;
				}
				break;
			/*case SDL_MOUSEMOTION:
					position_personnage.x = Evenement.motion.x - personnage->w / 2;
					position_personnage.y = Evenement.motion.y - personnage->h / 2;
				break;*/
		}

	/*Remplie la surface screen avec la couleur defini dans SDL_MapRGB*/
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 38, 196, 236));
		SDL_BlitSurface(img_background, NULL, screen, &position_background);
		SDL_BlitSurface(personnage, NULL, screen, &position_personnage);
		SDL_BlitSurface(fir, NULL, screen, &position_fir);
		SDL_Flip(screen);
	}

	/*Je libere les surface creer*/
	SDL_FreeSurface(fir);
	SDL_FreeSurface(personnage);
	SDL_Quit();
	return EXIT_SUCCESS;
}
