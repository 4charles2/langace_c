#include "main.h"

int main(void){
    printf("Bienvenue dans mon jeu du pendu\n");
    ft_game_pendu();
    return 0;
}

void ft_game_pendu()
{
    st_game party;
	party.nb_coup_restant = 15;

	if( (party.nb_joueur = ft_choice_number_gamer()) == 2 )
	{
		printf("Ecrivez le mot a deviner :\n");
		scanf("%s", party.mot_mystere);
		def_videBuffer();
		ft_upper_string(&party);
	}
	else
		ft_draw_word_dico(&party);

	ft_resolution_game(&party);

	printf("%s", party.mot_mystere);
}

int ft_choice_number_gamer()
{
	int choix = 0;

	printf("Choisissez le nombre de joueur\n1.Un joueur\n2.Deux joueur\nEntrez un choix(1 ou 2) : ");

	scanf("%d", &choix);
	def_videBuffer();
	
	switch(choix)
	{
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	default :
		printf("Vous n'avez pas entré un bon choix recommencé\n");
		ft_choice_number_gamer();
		break;
	}
	return 1;
}
