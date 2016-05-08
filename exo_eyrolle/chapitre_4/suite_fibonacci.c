#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int ft_convertCharInt(char argv[1]);
int ft_suite_fibonacci(int n);

int main (int argc, char **argv)
{
	if(argc < 2)
		exit(EXIT_FAILURE);

	int resultat = ft_suite_fibonacci(ft_convertCharInt(argv[1]));
	printf("Le résultat %d\n", resultat);
	return EXIT_SUCCESS;
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

int ft_suite_fibonacci(int n)
{
	int som = 1, fb = 1;
	if(n<2)
	{
		if(n == 0)
			return 0;
	return 1;;
	}

	for(int i = 2; i <= n; i++)
	{
		fb = som - fb;
		som += fb;
		
	}

	return som;
}
