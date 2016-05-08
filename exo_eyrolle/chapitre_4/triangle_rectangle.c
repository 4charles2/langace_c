#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_convertCharInt(char *number);

int main (int argc, char **argv)
{
	if(argc < 1)
		exit(EXIT_FAILURE);

	int nbLigne = ft_convertCharInt(argv[1]);
	for(int i = 0, e = 0; i<nbLigne; i++, e++)
	{
		for(int c = 0; printf("*"),c < e; c++);
		printf("%d%d\n",e, i);
	}
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
		dizaine = number[i]; /*Convertion en int*/
		dizaine -= 48;/*Convertion équivalent ascci en nombre*/
		dizaine *= multiplicateur;
		num += dizaine;
	}

	return num += unite;
}
