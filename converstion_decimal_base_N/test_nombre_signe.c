#include <stdio.h>
#include <stdlib.h>

//On depasse la valeur maximum pour la variable Soit 128 pour char qui peut aller jusqu'a la valeur 127 mais qui donne 128 résultat avce le zero
int main (void)
{
	
	char k = 0;
	do
	{
		printf("%ld\n", k);
		k++;
	}while(k>=0);
	{
		printf("%ld\n", k);
	}
	return EXIT_SUCCESS;
}
