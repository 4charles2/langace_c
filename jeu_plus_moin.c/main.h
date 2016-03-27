typedef struct st_game st_game;
struct  st_game
{
    int nb_joueur;
    int max;
    int numberMystery;
    int nb_tour;
    int answer_gamer;
};

void game();
void retry_game();
void ft_number_mystery(st_game* party);
void verif_answer_numberMystery(int answer, int numberMystery, int i);
void choice_difficulty(st_game* party);
