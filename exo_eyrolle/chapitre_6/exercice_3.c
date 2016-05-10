#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ft_compteur(void);
long ft_convertCharInt(char *number);

int main (int argc, char **argv)
{
	if(argc < 2)
		exit(EXIT_FAILURE);

	long nb = ft_convertCharInt(argv[1]), i = 0;
	while(ft_compteur(),nb > ++i);

	return EXIT_SUCCESS;
}

void ft_compteur()
{
	static long i;
	static long quotien = 10;

	if(!(i%quotien))
	{
		printf("%ld\n", i);
		quotien*=10;
	}

	i++;
}


long ft_convertCharInt(char *number)
{
	int unite = 0;
	long dizaine = 0;
	long num = 0;
	long taille = strlen(number);
	unite = number[taille-1];
	unite -= 48;
	for(long i=taille-2, multiplicateur = 10; i >= 0; i--, multiplicateur *= 10)
	{
		dizaine = number[i];
		dizaine -= 48;
		dizaine *= multiplicateur;
		num += dizaine;
	}

	return num += unite;
}
