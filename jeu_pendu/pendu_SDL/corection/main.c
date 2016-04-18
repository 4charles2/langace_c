#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <time.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#define NOMBRE_ESSAIS  7

enum {JEU_TERMINE, JEU_EN_COURS};
enum {OUI, NON};
//------------------------------------

int piocherMot(char *motPioche);
int nombreAleatoire(int nombreMax);

int main(int argc, char *argv[])
{
	SDL_Surface *ecran = NULL, *img = NULL; // On créé 2 surfaces pour le texte et pour l'image

	SDL_Event event;    // Evenement
	int continuer = 1;
	srand(time(NULL));  // pour le nombre aléatoire

	char lettrePropose = '\b';	// on va stocker ici la lettre tapée
	char motMystere[50];	//	Le mot mystère à découvrir
	if ( piocherMot(motMystere) == 0 )		// on demande un mot qui sera mis dans motMystere
		return EXIT_FAILURE;	// si on n'a pas réussi à charger le dictionnaire on arrête le programme

	const int tailleMot = strlen(motMystere);
	char *motMystereEnCours = NULL;    // Allocation dynamique de la mémoire
	motMystereEnCours = (char *) malloc(tailleMot * sizeof(char));
	if (motMystereEnCours == NULL)  // Verification de l'allocation de memoire
		return EXIT_FAILURE;  // On arrete tout

	strcpy(motMystereEnCours, motMystere);      // on copie le mot mystère dans une autre chaine
	char tableauDeSaugegardeDesLettresTape[] = "                          " ;		// 26 caractères on retient les lettres que le joueur a tapé

	int nombreEssais = NOMBRE_ESSAIS;
	int reussi = JEU_EN_COURS;		// Permet de savoir si le joueur à découvert le mot, on pourra aussi lui demander si il veut recommencer une autre partie
	int nombreEssaisRajoute = 0;	// Cette variable a un rapport avec le nombre d'essais.
	int sauterUnTour = NON;		// Cette variable permet de sauter le tour du joueur si il tape une lettre une seconde fois
	int i = 0;

	SDL_Init(SDL_INIT_VIDEO);
	ecran             = SDL_SetVideoMode(750, 320, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

	TTF_Init();		// initialisation de la SDL
	TTF_Font *police = NULL, *policePourFinal = NULL, *policePourTableau;	// création de 3 polices
	SDL_Color couleurNoire = {0, 0, 0};
	police            = TTF_OpenFont("godzilla.ttf", 45);
	policePourTableau = TTF_OpenFont("alphawood.ttf", 25);
	policePourFinal   = TTF_OpenFont("west.ttf", 65);

	SDL_Rect positionTexte, positionImage;	// création de 2 positions
	positionTexte.x = 0;
	positionTexte.y = 0;
	positionImage.x = 400;
	positionImage.y = 0;

	SDL_WM_SetCaption("Pendu en SDL pour les Zeros", NULL);

	for ( i = 0 ; i < tailleMot ; i++ )    // on code le motMystere
	{
		motMystereEnCours[i] = '*';
	}

	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch (event.type)
		{
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						continuer = 0;
						break;
					default :
						lettrePropose = event.key.keysym.sym;
						switch (lettrePropose)
						{
							case 'q' :
								lettrePropose = 'a';
								break;
							case ';' :
								lettrePropose ='m';
								break;
							case 'z' :
								lettrePropose ='w';
								break;
							case 'a' :
								lettrePropose = 'q';
								break;
							case 'w' :
								lettrePropose ='z';
								break;
						}
						lettrePropose = toupper(lettrePropose);  //majuscule
						break;
				}
		}

		//--------------------------------------------------------------------------------------------------
		if ( lettrePropose >= 'A' &&  lettrePropose <= 'Z' || lettrePropose == '\b')    // On annule la touche si ce n'est pas une lettre qui est tapée
		{
			sauterUnTour = NON;	// on initialise la variable
			for ( i = 0 ; i < 26 ; i++ )	// on parcourt entièrement le tableau qui sauvegarde les lettres
			{
				if ( tableauDeSaugegardeDesLettresTape[i] == lettrePropose && lettrePropose != '\b')	// Si on a trouvé la lettre que le joueur a tapé
				{
					sauterUnTour = OUI; // on ne joue pas
				}
			}

			//--------------------------------------------------------------------------------------------------
			if ( sauterUnTour == NON)   // On peut continuer le programme
			{

				//--------------------------------------------------------------------------------------------------
				if ( lettrePropose != '\b')  // Le joueur tente une lettre, on lui retire son essai
					nombreEssais--;

				//--------------------------------------------------------------------------------------------------
				for ( i = 0 ; i <= tailleMot ; i++ ) // On parcourt l'ensemble des lettres du mot mystère
				{
					if ( motMystere[i] == lettrePropose )	// Si on a une similitude
					{
						motMystereEnCours[i] = lettrePropose;	// On change le tableau que l'on va afficher
						if ( nombreEssaisRajoute == 0 )
						{
							nombreEssais++;	    // on lui remet son essai
							nombreEssaisRajoute++;    // on empêche de rajouter autant d'essais qu'il y a de similitudes
						}
					}
				}
				nombreEssaisRajoute = 0;    // le for est fini, on réinitialise la variable

				//--------------------------------------------------------------------------------------------------
				switch(nombreEssais)  // On blitte des images différentes en fonctions du nombre d'essais
				{
					case 7 : img = IMG_Load("potence_alpha.png");  // En pleine forme
					case 6 : img = IMG_Load("corde.png");
					case 5 : img = IMG_Load("tabouret_pendu.png");
					case 4 : img = IMG_Load("pendu_vivant.png");
					case 3 : img = IMG_Load("trou.png");
					case 2 : img = IMG_Load("potence_alpha.jpeg");
					case 1 : img = IMG_Load("pendu.png");  // attention, ici
					default: img = IMG_Load("index.jpeg");  // et pendu !
				}

				//--------------------------------------------------------------------------------------------------
				reussi = JEU_TERMINE;	// on initialise la variable
				for ( i = 0 ; i<= tailleMot ; i++ ) // on prend le mot secret lettre par lettre
				{
					if ( motMystereEnCours[i] == motMystere[i] || motMystereEnCours[i] == '\b');		// Si on a trouvé une lettre
					else
						reussi = JEU_EN_COURS;
				}
				if ( lettrePropose != '\b' )
					tableauDeSaugegardeDesLettresTape[lettrePropose-'A'] = lettrePropose; // on sauvegarde les lettres à son emplacement alphabétique

				//On blitte tout------------------------------------------------------------------------------------
				SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 210, 210, 255));	// on efface

				SDL_BlitSurface(img, NULL, ecran, &positionImage);	// on blitte l'image
				positionTexte.x = 50;
				positionTexte.y = ecran->h/2;
				SDL_BlitSurface(TTF_RenderText_Blended(police, motMystereEnCours, couleurNoire), NULL, ecran, &positionTexte);	// on blitte le mot secret
				positionTexte.x = 10;
				positionTexte.y = 275;
				SDL_BlitSurface(TTF_RenderText_Blended(policePourTableau, tableauDeSaugegardeDesLettresTape, couleurNoire), NULL, ecran, &positionTexte);	// on blitte les caractères déjà tapés
				//--------------------------------------------------------
				if ( reussi == JEU_TERMINE )  // Si on a gagné
				{
					SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 210, 210, 255));
					positionTexte.x = 10;
					positionTexte.y = 120;
					SDL_BlitSurface(TTF_RenderText_Blended(policePourFinal, "Felicitation ! Le mot etait bien :", couleurNoire), NULL, ecran, &positionTexte);
					positionTexte.x = 50;
					positionTexte.y = 180;
					SDL_BlitSurface(img, NULL, ecran, &positionImage);
					SDL_BlitSurface(TTF_RenderText_Blended(police, motMystereEnCours, couleurNoire), NULL, ecran, &positionTexte);
				}
				//--------------------------------------------------------
				if ( nombreEssais == 0 )  // Si on a perdu
				{
					SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 210, 210, 255));
					positionTexte.x = 10;
					positionTexte.y = 120;
					SDL_BlitSurface(TTF_RenderText_Blended(policePourFinal, "Perdu ! Le mot etait : ", couleurNoire), NULL, ecran, &positionTexte);
					positionTexte.x = 50;
					positionTexte.y = 180;
					SDL_BlitSurface(img, NULL, ecran, &positionImage);
					SDL_BlitSurface(TTF_RenderText_Blended(police, motMystere, couleurNoire), NULL, ecran, &positionTexte);
				}

			}
			SDL_Flip(ecran);
		}
	}

	TTF_CloseFont(police);    // on vide la mémoire
	TTF_CloseFont(policePourFinal);
	TTF_CloseFont(policePourTableau);
	TTF_Quit();
	SDL_FreeSurface(img);
	free(motMystereEnCours);
	SDL_Quit();

	return EXIT_SUCCESS;
}

int piocherMot(char *motPioche)
{
	FILE* dico = NULL;
	int nombreMots = 0, numMotChoisi = 0;
	int caractereLu = 0;
	dico = fopen("dico.txt", "r");
	if (dico == NULL)   //
	{
		return 0;
	}
	do
	{
		caractereLu = fgetc(dico);
		if (caractereLu == '\n')
			nombreMots++;
	}
	while (caractereLu != EOF);
	numMotChoisi = nombreAleatoire(nombreMots);
	rewind(dico);
	while (numMotChoisi > 0)
	{
		caractereLu = fgetc(dico);
		if (caractereLu == '\n')
			numMotChoisi--;
	}
	fgets(motPioche, 100, dico);
	motPioche[strlen(motPioche) - 1] = '\0';
	fclose(dico);
	return 1;
}

int nombreAleatoire(int nombreMax)
{
	return (rand() % nombreMax);
}

