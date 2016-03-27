#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "main.h"

int main(){

    printf("Bienvenue dans mon petit programme\n");
    game();

    return 0;
}

void game ()
{
    st_game party;
    party.nb_tour = 15;
    choice_difficulty(&party);
    //Mettre en parametre un pointeur sur structure st_game party
    ft_number_mystery(&party);

    printf("Bonjour decouvrez le jeu plus ou moin\n");
    printf("Vous devez devinez le nombre mystere entre 1 et %d\n", party.max);

    while (party.answer_gamer != party.numberMystery)
    {
        printf("Il vous reste %d coup pour deviner le mot.\n", party.nb_tour);
        printf("Entrez le nombre mystere\n");
        scanf("%d", &party.answer_gamer);
        verif_answer_numberMystery(party.answer_gamer, party.numberMystery, party.nb_tour);
        party.nb_tour--;
     }
     retry_game();
}

void choice_difficulty(st_game* party)
{
    int choice = 0;

    printf("Choix de la difficulté\n");
    printf("1. facile(1 à 100)\n");
    printf("2. moyen(1 à 500)\n");
    printf("3. difficile(1 à 1000)\n");

    int res = scanf("%d", &choice);

    if(res)
    {
        switch(choice)
        {
            case 1:
               party->max = 100;
               break;
            case 2:
               party->max = 500;
               break;
            case 3:
               party->max = 1000;
               break;
            default :
               party->max = 100;
               break;
        }
    }
    else
        printf("Mauvaise entrer !\n");
}

int choice_number_gamer()
{
    int nb_gamer = 1;

    printf("Choisissez le nombre de joueur\n");
    printf("1.joueur\n");
    printf("2.joueur\n");
    scanf("%d", &nb_gamer);

    switch(nb_gamer)
    {
        case 1:
            return 1;
            break;
        case 2:
            //faire un envoi sur game 
            return 2;
            break;
        default :
            printf("Mauvaise entrer (1joueur par defaut)\n");
            return 1;
            break;
    }
}

void verif_answer_numberMystery(int answer, int numberMystery, int i)
{
        if (answer == numberMystery)
            printf("Bravo vous avez trouver le nombre mystere\n");
        else if (answer < numberMystery)
            printf("C'est plus\n");
        else if (answer > numberMystery)
            printf("C'est moins\n");
        else
            printf("Vous n'avez pas entre un bon numero\n");
        if (!i)
        {
            printf("Vous avez perdu !\n");
            retry_game();
        }
}

void ft_number_mystery(st_game* party)
{
    const int MIN = 1;
    if(choice_number_gamer() == 2)
    {
        printf("Joueur 2 entrer le nombre mystere a deviner\n");
        printf("Entre 1 et %d\n", party->max);
        scanf("%d", &party->numberMystery);
    }
    else
    {
        srand(time(NULL));
        party->numberMystery = (rand() % (party->max - MIN + 1)) + MIN;
    }
}

void retry_game()
{
    int retry = 2;
    printf("voulez vou refaire une partie !\n");
    printf("1.Oui\n2.Non\n");
    printf("Entrez votre choix :\n");

    scanf("%d", &retry);

    switch(retry)
    {
        case 1:
            game();
            break;
        case 2:
            printf("Au revoir");
            return ;
            break;
        default:
            printf("Vous n'avez pas entrer un bon choix");
            break;
    }
}
