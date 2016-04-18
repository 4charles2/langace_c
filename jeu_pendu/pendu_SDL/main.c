/*
main.c
------

Par Charles Tognol, Pour le jeu du pendu

Rôle : main.c
*/
#include <stdio.h>
#include <stdlib.h>
#include "constante.h"
#include "game.h"

int main(void)
{
	if(!ft_game())
		fprintf(stderr, "fonction game error return");

	SDL_Quit();

	return EXIT_SUCCESS;

}
