#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_convertCharInt(char *number);


void ft_affiche_table_multiplication();

int main (int argc, char **argv)
{
	if(argc < 2)
		printf("Vous n'avez pas entrer d'argument");
	
	int tableMax = ft_convertCharInt(argv[1]);

	ft_affiche_table_multiplication(tableMax);
	return EXIT_SUCCESS;
}

void ft_affiche_table_multiplication(int tableMax)
{
	int i = 0;
	printf("     I");
	for(i = 1; printf("%4d", i), i < tableMax; i++);
	printf("\n------");
	for(i = 1; printf("----"), i < tableMax ; i++);
	for(i = 1; i <= tableMax; i++)
	{
		printf("\n%4d", i);
		printf(" I");
		for(int y = 1; y <= tableMax; y++)
		{
			printf("%4d", y*i);
		}
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
		dizaine = number[i];
		dizaine -= 48;
		dizaine *= multiplicateur;
		num += dizaine;
	}

	return num += unite;
}
