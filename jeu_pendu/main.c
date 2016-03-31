#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "main.h"

int main(){
    printf("Bienvenue dans mon jeu du pendu\n");
    game_pendu();
    return 0;
}

void game_pendu()
{
    st_game party;
    if(creation_mystery_word(&party))
        printf("%s", party.mot_mystere);
    else
        printf("Le mot mystere n'à pas été créer");
}

int creation_mystery_word(st_game* party)
{
    FILE* dico = NULL;

    srand(time(NULL));
    int number_rand = (rand()%8);
    printf("%d", number_rand);
    //fseek(dico, number_rand, SEEK_SET);
    dico = fopen("dico.txt", "r");
    if(dico == NULL)
        printf("Le dictionnaire ne c'est pas ouvert");
    if(fgets(party->mot_mystere, 30, dico))
    {
        fclose(dico);
        return 1;
    }
    else
        return 0;
}
