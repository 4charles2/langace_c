#ifndef __GAME__
#define __GAME__
	#include "constante.h"
	int ft_game(void);
	void ft_init_SDL(t_show* party);
	void ft_engine_game(t_show* party);
	void ft_blit_surface(t_show* party);
	void  ft_free_surface(t_show* party);
	void ft_check_hit_keyboard(t_show* party, SDL_Event event);
#endif
