#ifndef __SRAND__
#define __SRAND__
	#define def_srand srand(time(NULL));
#endif
#ifndef __WORDMYSTERY__
#define __WORDMYSTERY__
	#include "constante.h"
	typedef struct s_manip_dico
	{
		int nb_word_dico;
		char char_read;
		int num_word_draw;
	}t_manip_dico;
	void ft_fill_word_answer(t_show* party);
	void ft_empty_buffer(void);
	int ft_word_mystery(t_show *party);
	void ft_count_word_dico(t_manip_dico* manip, FILE *dico);
	void ft_draw_word_dico(t_manip_dico* manip, FILE *dico, t_show *party);
#endif
