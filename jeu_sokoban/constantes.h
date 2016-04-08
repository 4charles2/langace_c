/*
constantes.h
------------

Par Charles Tognol, Pour le jeu du sokoba

Rôle : defini toutes les constantes du jeu Global
Taille de la fenetre des blocs et autre
*/

#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

	#define TAILLE_BLOC				34
	#define NB_BLOCS_LARGEUR			12
	#define NB_BLOCS_HAUTEUR			12
	#define LARGEUR_FENETRE			TAILLE_BLOC * NB_BLOCS_LARGEUR
	#define HAUTEUR_FENETRE			TAILLE_BLOC * NB_BLOCS_HAUTEUR

	enum {HAUT, BAS, GAUCHE, DROITE};
	enum {VIDE, MUR, CAISSE, OBJECTIF, MARIO, CAISSE_OK};

#endif
