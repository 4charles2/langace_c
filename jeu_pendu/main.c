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
    creation_mystery_word(&party);
}

int creation_mystery_word(st_game* party)
{
    FILE* dico = NULL;
    dico = fopen("dico.txt", "r");
    if(dico == NULL)
        printf("Le dictionnaire ne c'est pas ouvert");
    fgets(party->mot_mystere, 30, fichier);
    fclose(dico);
}
