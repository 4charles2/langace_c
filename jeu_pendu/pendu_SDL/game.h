#ifndef __GAME__
#define __GAME__
	#include "constante.h"
	int ft_game(void);
	int ft_init_SDL(t_show* party);
	int ft_engine_game(t_show* party);
	void ft_blit_surface(t_show* party);
	int  ft_free_surface(t_show* party);
	void ft_check_char(t_show* party, char c, int* y);
	int  ft_blit_surface_pendu(t_show* party);
	void ft_game_over(t_show* party, int finish);
	void ft_vide_buffer();
#endif
