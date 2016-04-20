#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "constante.h"
#include "wordMystery.h"

int ft_word_mystery(t_show *party)
{
	FILE *dico = fopen("dico.txt", "r");
	t_manip_dico manip;

	ft_count_word_dico(&manip, dico);
	ft_draw_word_dico(&manip, dico, party);
	ft_fill_word_answer(party);

	fclose(dico);

	return 1;
}

void ft_draw_word_dico(t_manip_dico* manip, FILE *dico, t_show *party)
{
	def_srand;
	manip->num_word_draw = rand()%manip->nb_word_dico;

	rewind(dico);
	while(manip->num_word_draw > 0)
	{
		if(fgetc(dico) == '\n')
			manip->num_word_draw--;

	}
	fgets(party->mystery_word, sizeof(party->mystery_word), dico);
	party->mystery_word[strlen(party->mystery_word)-1] = '\0';
}

void ft_count_word_dico(t_manip_dico* manip, FILE *dico)
{
	manip->char_read = ' ';
	manip->nb_word_dico = 0;
	while(manip->char_read != EOF)
	{
		manip->char_read = fgetc(dico);
		if(manip->char_read == '\n')
			manip->nb_word_dico++;

	}
}

void ft_fill_word_answer(t_show* party)
{
	int taille = strlen(party->mystery_word), i = 0;
	while(taille > i)
	{
		party->answer_word[i] = '*';
		i++;
	}
	party->answer_word[i] = '\0';
}

void ft_empty_buffer()
{
	int c;
	while(c != '\n' && c != EOF)
	{
		c = getchar();
	}
}
