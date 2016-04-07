#include "main.h"

void ft_resolution_game(st_game* party)
{

	while(!ft_verif_win(party) && party->nb_coup_restant > 0)
	{
		printf("\nIl vous reste encore %d nombre d'essai\n", party->nb_coup_restant);
		printf("Ecrivez une lettre afin de deviner le mot mytere :\n");
		if(ft_check_char(party))
		{
			printf("\nBravo vous avez trouvez une lettre\n %s \n", party->answer_gamer);
			party->nb_coup_restant--;
			ft_resolution_game(party);
		}
		else
		{
			printf("\nDésoler mais la lettre n'est pas dans le mot\n%s\n", party->answer_gamer);
			party->nb_coup_restant--;
			ft_resolution_game(party);
		}
	}
	ft_winner_game();
}

int ft_check_char(st_game* party)
{
	int i = 0;
	int ok = 0;

	char c = ft_char_read();

	while(party->mot_mystere[i] != '\0')
	{
		if(c == party->mot_mystere[i])
		{
			party->answer_gamer[i] = c;
			ok = 1;
		}
		i++;
	}
	return ok;
}

int ft_verif_win(st_game* party)
{
	int i = 0;
	int word_complet = 1;

	while(party->answer_gamer[i] != '\0')
	{
		if(party->answer_gamer[i] == '*')
			word_complet = 0;
	i++;
	}

	return word_complet;
}

char ft_char_read()
{
	char c = ' ';

	printf("Tapez la lettre : ");

	c = getchar();
	while(getchar() != '\n');

	c = toupper(c);
	return c;
}

void ft_winner_game()
{
	int choix = 0;

	printf("\nBravo vous avez gagner le jeu\n");
	printf("Voulez refaire une partie ou quitter le jeu\n");
	printf("1.quitter le Jeu\n2.refaire une partie\n");
	scanf("%d", &choix);
	switch(choix)
	{
	case 1:
		exit(0);
		break;
	case 2:
		ft_game_pendu();
		break;
	default:
		printf("Vous n'avez pas entrer un bon choix recommencer\n");
		ft_winner_game();
		break;
	}
}
