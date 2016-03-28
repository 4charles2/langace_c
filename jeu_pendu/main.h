typedef struct st_game st_game;
struct st_game
{
    int nb_coup_restant;
    char answer_gamer;
    char *mot_mystere;
    int nb_joueur;
}
void game_pendu();
