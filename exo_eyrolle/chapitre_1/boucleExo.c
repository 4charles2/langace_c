#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int nb = 0, som = 0, i = 0;
	do {} while(printf("Ecriver un nombre :"),scanf("%d", &nb), som += nb,++i < 4);
	/*Pareil sans do sauf qu'il n'y pas besoin des {}*/
	printf("Voici la somme des nombres : %d\n", som);
	return EXIT_SUCCESS;
}
