#ifndef DEF_FICHIERS
#define DEF_FICHIERS
#include "constantes.h"
	int chargerNiveau(int niveau[][NB_BLOCS_HAUTEUR], int niveauActuel);
	int sauvegarderNiveau(int niveau[][NB_BLOCS_HAUTEUR]);
	void choice_level(char *ligneFichier, int niveauActuel);

#endif
