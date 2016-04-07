#ifndef DEF_BIBLIO
#define DEF_BIBLIO
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <string.h>
	#include <time.h>
	#include <gtk/gtk.h>
#endif

#ifndef DEF_SRAND
#define DEF_SRAND
	#define def_srand srand(time(NULL));
#endif

#ifndef DEF_VIDE_BUFFER
#define DEF_VIDE_BUFFER
	#define def_videBuffer() while(getchar() != '\n')
#endif

#ifndef DEF_DICO
#define DEF_DICO

typedef struct st_game
{
    int nb_coup_restant;
    char answer_gamer[30];
    char mot_mystere[30];
    int nb_joueur;
}st_game;

typedef struct st_management_dico
{
	int nb_word;
	int char_read;
	int nb_word_rand;
}st_management_dico;

void ft_game_pendu(void);
int ft_creation_mystery_word(st_game* party);
int ft_draw_word_dico(st_game *party);
void ft_number_word_rand(st_management_dico* st_dico);
int ft_choice_number_gamer(void);
void ft_upper_string(st_game* party);
void ft_resolution_game(st_game* party);
void ft_fill_answer_gamer(int size_word, st_game* party);
void ft_winner_game(void);
int ft_check_char(st_game* party);
int ft_verif_win(st_game* party);
char ft_char_read(void);

#endif
