#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void ft_calcul_nb_premier(int nombre);
int ft_convertCharInt(char *number);

int main (int argc, char **argv)
{
	if(argc < 2)
		exit(EXIT_FAILURE);

	int nombre = ft_convertCharInt(argv[1]);

	ft_calcul_nb_premier(nombre);

	return EXIT_SUCCESS;
}

void ft_calcul_nb_premier(int nombre)
{
	int racine = sqrt(nombre), premier = 1, i = 0;
	for( i = 2; i <= racine && premier; i++)
		if(!(nombre%i))
			premier = 0;;

	if(premier)
		printf("C'est un nombre premier\n");
	else
		printf("Le nombre n'est pas premier car il se divise par %d\n", i);

}

int ft_convertCharInt(char *number)
{
	int unite = 0, dizaine = 0;
	int num = 0;
	int taille = strlen(number);
	unite = number[taille-1];
	unite -= 48;
	for(int i=taille-2, multiplicateur = 10; i >= 0; i--, multiplicateur *= 10)
	{
		dizaine = number[i];
		dizaine -= 48;
		dizaine *= multiplicateur;
		num += dizaine;
	}

	return num += unite;
}
