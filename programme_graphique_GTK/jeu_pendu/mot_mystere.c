#include "main.h"

void ft_upper_string(st_game* party)
{
	int i = 0;

	while(party->mot_mystere[i] != '\0')
	{
		party->mot_mystere[i] = toupper(party->mot_mystere[i]);
		i++;
	}
}

void ft_number_word_rand(st_management_dico* st_dico)
{
	def_srand;
    st_dico->nb_word_rand = (rand()%st_dico->nb_word);
}

int ft_draw_word_dico(st_game* party)
{
	int size_word = 0;
    FILE* f_dico = NULL;

	st_management_dico st_dico;
	st_dico.nb_word = 0;
    f_dico = fopen("dico.txt", "r");

    if(f_dico == NULL)
	{
        printf("Le dictionnaire ne c'est pas ouvert\n");
		exit(0);
	}

	while(st_dico.char_read != EOF)
	{
		st_dico.char_read = fgetc(f_dico);

		if(st_dico.char_read == '\n')
			st_dico.nb_word++;
	}

	ft_number_word_rand(&st_dico);
	rewind(f_dico);

	while(st_dico.nb_word_rand > 0)
	{
		st_dico.char_read = fgetc(f_dico);

		if(st_dico.char_read == '\n')
			st_dico.nb_word_rand--;

	}

    fgets(party->mot_mystere, sizeof(party->mot_mystere), f_dico);

	size_word = strlen(party->mot_mystere);
    party->mot_mystere[size_word -1] = '\0';
/*remettre le -1 ou pas avant le ] pour remplacer \n par \0 */
	ft_fill_answer_gamer(size_word, party);

    fclose(f_dico);

	return 1;
}

void ft_fill_answer_gamer(int size_word, st_game* party)
{
	int i = 0;
	while(i < (size_word - 1))
	{
		party->answer_gamer[i] = '*';
		i++;
	}
	party->answer_gamer[i] = '\0';
}
