#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_convertCharInt(char *number);
long ft_factorielle(int facteur);

int main (int argc, char **argv)
{
	if(argc < 2)
	{
		printf("Vous n'avez pas entrerd'arguments !\n");
		exit(EXIT_FAILURE);
	}

	int nb = ft_convertCharInt(argv[1]);
	printf("%ld\n",ft_factorielle(nb));

	return EXIT_SUCCESS;
}

long ft_factorielle(int facteur)
{
	if (facteur>1) return (ft_factorielle(facteur-1)*facteur);
	else return 1;
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
