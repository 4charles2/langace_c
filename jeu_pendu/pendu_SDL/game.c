#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include "wordMystery.h"
#include "game.h"

int ft_game()
{
	t_show party;

	strcat(party.character_already,".......");
	party.nb_shots = 6;

	if(!ft_word_mystery(&party))
		fprintf(stderr, "erreur draw word dico");

	printf("Le mot mystere1 : %s\n", party.mystery_word);
	printf("Le mot answer1  : %s\n", party.answer_word);

	if(ft_init_SDL(&party))
		fprintf(stderr, "initSDL OK");

	if(ft_engine_game(&party))
		fprintf(stderr, "engine_game ok");

	if(ft_free_surface(&party))
		fprintf(stderr, "free surface ok");

	return 1;
}

int ft_engine_game(t_show* party)
{
	int continuer = 1, y = 0;
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
						ft_check_char(party, 'A', &y);
						break;
					case SDLK_b:
						ft_check_char(party, 'B', &y);
						break;
					case SDLK_c:
						ft_check_char(party, 'C', &y);
						break;
					case SDLK_d:
						ft_check_char(party, 'D', &y);
						break;
					case SDLK_e:
						ft_check_char(party, 'E', &y);
						break;
					case SDLK_f:
						ft_check_char(party, 'F', &y);
						break;
					case SDLK_g:
						ft_check_char(party, 'G', &y);
						break;
					case SDLK_h:
						ft_check_char(party, 'H', &y);
						break;
					case SDLK_i:
						ft_check_char(party, 'I', &y);
						break;
					case SDLK_j:
						ft_check_char(party, 'J', &y);
						break;
					case SDLK_k:
						ft_check_char(party, 'K', &y);
						break;
					case SDLK_l:
						ft_check_char(party, 'L', &y);
						break;
					case SDLK_m:
						ft_check_char(party, 'M', &y);
						break;
					case SDLK_n:
						ft_check_char(party, 'N', &y);
						break;
					case SDLK_o:
						ft_check_char(party, 'O', &y);
						break;
					case SDLK_p:
						ft_check_char(party, 'P', &y);
						break;
					case SDLK_q:
						ft_check_char(party, 'Q', &y);
						break;
					case SDLK_r:
						ft_check_char(party, 'R', &y);
						break;
					case SDLK_s:
						ft_check_char(party, 'S', &y);
						break;
					case SDLK_t:
						ft_check_char(party, 'T', &y);
						break;
					case SDLK_u:
						ft_check_char(party, 'U', &y);
						break;
					case SDLK_v:
						ft_check_char(party, 'V', &y);
						break;
					case SDLK_w:
						ft_check_char(party, 'W', &y);
						break;
					case SDLK_x:
						ft_check_char(party, 'X', &y);
						break;
					case SDLK_y:
						ft_check_char(party, 'Y', &y);
						break;
					case SDLK_z:
						ft_check_char(party, 'Z', &y);
						break;
					case SDLK_ESCAPE:
						continuer = 0;
						break;
					default:
						continuer = 1;
						break;
				}
				if(!party->nb_shots)
					ft_game_over(party, 0);
				else if(!strcmp(party->answer_word, party->mystery_word))
					ft_game_over(party, 1);

				/*ft_vide_buffer();*/
				break;
			default:
				continuer = 1;
				break;
		}
	}
	return 1;
}

void ft_check_char(t_show* party, char c, int* y)
{
	int i = 0;
	int letter_ok = 0;
	int taille = strlen(party->mystery_word);

	while(i < taille)
	{
		if(c == party->mystery_word[i])
		{
			party->answer_word[i] = c;
			letter_ok = 1;
		}

		i++;
	}

	if(!letter_ok)
	{
		party->character_already[*y] = c;
		party->nb_shots--;
		if(ft_blit_surface_pendu(party) != EXIT_SUCCESS)
			fprintf(stderr, "Erreur ft_blit_surface");

		(*y)++;
	}
	else
		ft_blit_surface(party);

}

int ft_blit_surface_pendu(t_show* party)
{
	int i = 7, y = 0;


	i = party->nb_shots - 7;
	if(i < 0)
		i = -i;

	while(y <= i)
	{
		ft_blit_surface(party);
		party->position_pendu[1].x = 244;
		party->position_pendu[1].y = 196;
		party->position_pendu[2].x = 352;
		party->position_pendu[2].y = 221;
		party->position_pendu[3].x = 322;
		party->position_pendu[3].y = 390;
		party->position_pendu[4].x = 295;
		party->position_pendu[4].y = 221;
		party->position_pendu[5].x = 250;
		party->position_pendu[5].y = 441;
		party->position_pendu[6].x = 296;
		party->position_pendu[6].y = 222;
		
		if(y < 6)
			SDL_BlitSurface(party->pendu[y], NULL, party->area[2], &party->position_pendu[y]);
		else
		{
			party->pendu[4] = IMG_Load("pendu.png");
			SDL_BlitSurface(party->pendu[4], NULL, party->area[2], &party->position_pendu[4]);
		}
		SDL_Flip(party->area[2]);
		y++;
	}
	return EXIT_SUCCESS;
}

int ft_init_SDL(t_show* party)
{

	SDL_Init(SDL_INIT_VIDEO);
	party->area[0] = SDL_SetVideoMode(950, 711, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	
	if(TTF_Init() == -1)
		fprintf(stderr, "error TTF_Init %s", TTF_GetError());

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
	if(!party->area[3])
		fprintf(stderr, "erreur IMG_Load image %s", IMG_GetError());

	party->pendu[1] = IMG_Load("potence_alpha.png");
	if(!party->pendu[1])
		fprintf(stderr, "erreur IMG_Load potence alpha %s", IMG_GetError());

	party->pendu[2] = IMG_Load("corde.png");
	if(!party->pendu[2])
		fprintf(stderr, "erreur IMG_Load corde.png %s", IMG_GetError());

	party->pendu[3] = IMG_Load("tabouret_pendu.png");
	if(!party->pendu[3])
		fprintf(stderr, "erreur IMG_Load tabouret %s", IMG_GetError());

	party->pendu[4] = IMG_Load("pendu_vivant.png");
	if(!party->pendu[4])
		fprintf(stderr, "erreur IMG_Load pendu vivant %s", IMG_GetError());

	party->pendu[5] = IMG_Load("trou.png");
	if(!party->pendu[5])
		fprintf(stderr, "erreur trou %s", IMG_GetError());

	return 1;
}

void ft_blit_surface(t_show* party)
{
	int i = 0, f = 0;
	SDL_Color color_font = {0, 0, 0, 0};
	char nb_coup[2];
	
	sprintf(nb_coup, "%d coups", party->nb_shots);


	SDL_FillRect(party->area[0], NULL, SDL_MapRGB(party->area[0]->format, 255, 255, 255));
	party->area[7] = IMG_Load("fenetreMotMystere_pendu.jpeg");
	i = 4;
	while(i <= 6)
	{
		if(!(party->area[i] = IMG_Load("fenetre_info.jpeg")))
			fprintf(stderr, "erreur IMG_Load fenetre_info %s", IMG_GetError());

		i++;
	}
	if(!party->area[7])
		fprintf(stderr, "erreur IMG_Load fenetreMotMystere_pendu %s", IMG_GetError());

	if(!(party->surface_font[0] = TTF_RenderText_Blended(party->font2, "Joueur 1", color_font)))
		fprintf(stderr, "error TTF joueur_1 %s", TTF_GetError());

	if(!(party->surface_font[1] = TTF_RenderText_Blended(party->font2, nb_coup, color_font)))
		fprintf(stderr, "error TTF nb coup %s", TTF_GetError());

	if(!(party->surface_font[2] = TTF_RenderText_Blended(party->font2, party->character_already, color_font)))
		fprintf(stderr, "error TTF lettre %s", TTF_GetError());

	if(!(party->surface_font[3] = TTF_RenderText_Blended(party->font2, party->answer_word, color_font)))
		fprintf(stderr, "error TTF party->answer_word %s", TTF_GetError());

	i = 1, f = 4;
	while(i <= 4)
	{
		party->position_font[i].x = party->area[f]->w / 2 - party->surface_font[i-1]->w / 2;
		party->position_font[i].y = party->area[f]->h / 2 - party->surface_font[i-1]->h / 2;
		i++;
		f++;
	}

	i = 0, f = 4;
	while(i <= 3)
	{
		if(0 != (SDL_BlitSurface(party->surface_font[i], NULL, party->area[f], &party->position_font[i+1])))
			fprintf(stderr, "error blit _font 0 %s", SDL_GetError());

		i++;
		f++;
	}

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

	if(0 != (SDL_BlitSurface(party->area[1], NULL, party->area[0], NULL)))
		fprintf(stderr, "error blit _area 1 %s", SDL_GetError());

	i = 2, f = 1;
	while(i <= 7)
	{
		if(0 != (SDL_BlitSurface(party->area[i], NULL, party->area[0], &party->position_decor[f])))
			fprintf(stderr, "error blit _area 2 %s", SDL_GetError());

		i++;
		f++;
	}
	
	i = 0;
	while(i < 8)
	{
		if(0 != (SDL_Flip(party->area[i])))
			fprintf(stderr, "error SDL_Flip %s", SDL_GetError());
		
		i++;
	}

	i = 0;
	while(i < 4)
	{
		if(0 != (SDL_Flip(party->surface_font[i])))
			fprintf(stderr, "error SDL_Flip surface font %s", SDL_GetError());

		i++;
	}

}

int ft_free_surface(t_show* party)
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


	TTF_CloseFont(party->font2);
	TTF_Quit();
	return 1;
}

void ft_vide_buffer()
{
	int c = 0;

	while(c != '\n' && c != EOF)
	{
		c = getchar();
	}
}

void ft_game_over(t_show* party, int finish)
{
	int continuer = 1;
	SDL_Event event;
	SDL_Rect pos;
	if(finish)
	{
		party->area[1] = IMG_Load("winner.png");
		pos.x = party->area[0]->w / 2 - party->area[1]->w /2;
		pos.y = party->area[0]->h / 2 - party->area[1]->h /2;
	}
	else
	{
		party->area[1] = IMG_Load("game_over.png");
		pos.x = party->area[0]->w / 2 - party->area[1]->w /2;
		pos.y = party->area[0]->h / 2 - party->area[1]->h /2;
	}

	SDL_BlitSurface(party->area[1], NULL, party->area[0], &pos);
	SDL_Flip(party->area[0]);

	while(continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				ft_free_surface(party);
				exit(EXIT_SUCCESS);
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						ft_free_surface(party);
						exit(EXIT_SUCCESS);
						break;
					case SDLK_y:
						ft_game();
						break;
					case SDLK_n:
						ft_free_surface(party);
						exit(EXIT_SUCCESS);
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
