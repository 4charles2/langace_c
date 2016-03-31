typedef struct st_game
{
    int nb_coup_restant;
    char answer_gamer;
    char mot_mystere[30];
    int nb_joueur;
}st_game;
void game_pendu();
int creation_mystery_word(st_game* party);
