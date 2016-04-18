#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include "wordMystery.h"
#include "game.h"

int ft_game()
{
	t_show party;

	if(!ft_word_mystery(&party))
		fprintf(stderr, "erreur draw word dico");

	printf("Le mot mystere1 : %s\n", party.mystery_word);
	printf("Le mot answer1  : %s\n", party.answer_word);

	ft_init_SDL(&party);

	ft_engine_game(&party);

	ft_free_surface(&party);

	return 1;
}

void ft_engine_game(t_show* party)
{
	int continuer = 1;
	SDL_Event event;

	ft_blit_surface(party);
	while(continuer)
	{
		SDL_WaitEvent(&event);

		switch(event.type)
		{
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_a:
						/*Tentation de récupération de la valeur d'une lettre afin de faire une comparaison numérique et de ensuite faire une convertion numérique int char caractere corespondant*/
						/*Ceci éviterai de devoir verifier chaque lettre*/
						 strcat(party->answer_word,"a");
						 ft_blit_surface(party);
						break;
					case SDLK_b:
						strcat(party->answer_word,"b");
						break;
					case SDLK_c:
						strcat(party->answer_word,"c");
						break;
					case SDLK_d:
						strcat(party->answer_word,"d");
						break;
					case SDLK_e:
						strcat(party->answer_word,"e");
						break;
					case SDLK_f:
						strcat(party->answer_word,"f");
						break;
					case SDLK_g:
						strcat(party->answer_word,"g");
						break;
					case SDLK_h:
						strcat(party->answer_word,"h");
						break;
					case SDLK_i:
						strcat(party->answer_word,"i");
						break;
					case SDLK_j:
						strcat(party->answer_word,"j");
						break;
					case SDLK_k:
						strcat(party->answer_word,"k");
						break;
					case SDLK_l:
						strcat(party->answer_word,"l");
						break;
					case SDLK_m:
						strcat(party->answer_word,"m");
						break;
					case SDLK_n:
						strcat(party->answer_word,"n");
						break;
					case SDLK_o:
						strcat(party->answer_word,"o");
						break;
					case SDLK_p:
						strcat(party->answer_word,"p");
						break;
					case SDLK_q:
						strcat(party->answer_word,"q");
						break;
					case SDLK_r:
						strcat(party->answer_word,"r");
						break;
					case SDLK_s:
						strcat(party->answer_word,"s");
						break;
					case SDLK_t:
						strcat(party->answer_word,"t");
						break;
					case SDLK_u:
						strcat(party->answer_word,"u");
						break;
					case SDLK_w:
						strcat(party->answer_word,"w");
						break;
					case SDLK_x:
						strcat(party->answer_word,"x");
						break;
					case SDLK_y:
						strcat(party->answer_word,"y");
						break;
					case SDLK_z:
						strcat(party->answer_word,"z");
						break;
					case SDLK_ESCAPE:
						continuer = 0;
						break;
					default:
						continuer = 1;
						break;
				}
				break;
			default:
				continuer = 1;
				break;
		}
	}
}

void ft_init_SDL(t_show* party)
{
	int i = 0;

	SDL_Init(SDL_INIT_VIDEO);
	party->area[0] = SDL_SetVideoMode(950, 711, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	
	if(TTF_Init() == -1)
		fprintf(stderr, "error TTF_Init %s", TTF_GetError());

	party->font = TTF_OpenFont("alphawood.ttf", 80);
	if(!party->font)
		fprintf(stderr, "erreur police alphawood.ttf %s", TTF_GetError());

	party->font2 = TTF_OpenFont("godzilla.ttf", 50);
	if(!party->font2)
		fprintf(stderr, "erreur police godzila.ttf %s", TTF_GetError());

	party->area[1] = IMG_Load("fond.jpeg");
	if(!party->area[1])
		fprintf(stderr, "erreur IMG_Load fond.jpeg %s", IMG_GetError());

	party->area[2] = IMG_Load("porteFort_pendu.jpeg");
	if(!party->area[2])
		fprintf(stderr, "erreur IMG_Load porteFort_pendu %s", IMG_GetError());

	party->area[3] = IMG_Load("images.png");
	if(!party->area[2])
		fprintf(stderr, "erreur IMG_Load image %s", IMG_GetError());

	i = 4;
	while(i <= 6)
	{

		if(!(party->area[i] = IMG_Load("fenetre_info.jpeg")))
			fprintf(stderr, "erreur IMG_Load fenetre_info %s", IMG_GetError());

		i++;
	}

	
	party->area[7] = IMG_Load("fenetreMotMystere_pendu.jpeg");
	if(!party->area[7])
		fprintf(stderr, "erreur IMG_Load fenetreMotMystere_pendu %s", IMG_GetError());


	party->position_decor[1].x = 10;
	party->position_decor[1].y = 7;
	party->position_decor[2].x = 697;
	party->position_decor[2].y = 15;
	party->position_decor[3].x = 694;
	party->position_decor[3].y = 155;
	party->position_decor[4].x = 694;
	party->position_decor[4].y = 288;
	party->position_decor[5].x = 694;
	party->position_decor[5].y = 416;
	party->position_decor[6].x = 119;
	party->position_decor[6].y = 594;


}

void ft_blit_surface(t_show* party)
{
	int i = 0, f = 4;
	SDL_Color color_font = {0, 0, 0, 0};

	SDL_FillRect(party->area[0], NULL, SDL_MapRGB(party->area[0]->format, 204, 229, 255));
	SDL_FreeSurface(party->surface_font[3]);
	if(!(party->surface_font[0] = TTF_RenderText_Blended(party->font2, "Joueur 1", color_font)))
		fprintf(stderr, "error TTF joueur_1 %s", TTF_GetError());

	if(!(party->surface_font[1] = TTF_RenderText_Blended(party->font2, "nb coup", color_font)))
		fprintf(stderr, "error TTF nb coup %s", TTF_GetError());

	if(!(party->surface_font[2] = TTF_RenderText_Blended(party->font2, "lettre", color_font)))
		fprintf(stderr, "error TTF lettre %s", TTF_GetError());

	if(!(party->surface_font[3] = TTF_RenderText_Blended(party->font, party->answer_word, color_font)))
		fprintf(stderr, "error TTF party->answer_word %s", TTF_GetError());

	i = 1;

	while(i <= 4)
	{
		party->position_font[i].x = party->area[f]->w / 2 - party->surface_font[i-1]->w / 2;
		party->position_font[i].y = party->area[f]->h / 2 - party->surface_font[i-1]->h / 2;
		i++;
		f++;
	}


	if(0 != (SDL_BlitSurface(party->surface_font[0], NULL, party->area[4], &party->position_font[1])))
		fprintf(stderr, "error blit _font 0 %s", SDL_GetError());

	if(0 != (SDL_BlitSurface(party->surface_font[1], NULL, party->area[5], &party->position_font[2])))
		fprintf(stderr, "error blit _font 1 %s", SDL_GetError());

	if(0 != (SDL_BlitSurface(party->surface_font[2], NULL, party->area[6], &party->position_font[3])))
		fprintf(stderr, "error blit _font 2 %s", SDL_GetError());

	if(0 != (SDL_BlitSurface(party->surface_font[3], NULL, party->area[7], &party->position_font[4])))
		fprintf(stderr, "error blit _font 3 %s", SDL_GetError());

	if(0 != (SDL_BlitSurface(party->area[1], NULL, party->area[0], NULL)))
		fprintf(stderr, "error blit _area 1 %s", SDL_GetError());

	if(0 != (SDL_BlitSurface(party->area[2], NULL, party->area[0], &party->position_decor[1])))
		fprintf(stderr, "error blit _area 2 %s", SDL_GetError());

	if(0 != (SDL_BlitSurface(party->area[3], NULL, party->area[0], &party->position_decor[2])))
		fprintf(stderr, "error blit _area 3 %s", SDL_GetError());

	if(0 != (SDL_BlitSurface(party->area[4], NULL, party->area[0], &party->position_decor[3])))
		fprintf(stderr, "error blit _area 4 %s", SDL_GetError());

	if(0 != (SDL_BlitSurface(party->area[5], NULL, party->area[0], &party->position_decor[4])))
		fprintf(stderr, "error blit _area 5 %s", SDL_GetError());

	if(0 != (SDL_BlitSurface(party->area[6], NULL, party->area[0], &party->position_decor[5])))
		fprintf(stderr, "error blit _area 6 %s", SDL_GetError());

	if(0 != (SDL_BlitSurface(party->area[7], NULL, party->area[0], &party->position_decor[6])))
		fprintf(stderr, "error blit _area 7 %s", SDL_GetError());
	

	while(i < 7)
	{
		if(0 != (SDL_Flip(party->area[i])))
			fprintf(stderr, "error SDL_Flip %s", SDL_GetError());
		
		i++;
	}

}

void ft_free_surface(t_show* party)
{
	int i = 0;

	while(i <= 3)
	{
		SDL_FreeSurface(party->surface_font[i]);
		i++;
	}
	i = 1;
	while(i <= 7)
	{
		SDL_FreeSurface(party->area[i]);
		i++;
	}


	TTF_Quit();
}
