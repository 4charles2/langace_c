#include <stdio.h>
#include <stdlib.h>

void ft_min_max(int *tab, int taille, int *adrmin, int *adrmax);

int main (void)
{
	int taille = 0, max = 0, min = 0;
	printf("Entrez le nombre de chiffre que vous voulez\n");
	scanf("%d", &taille);
	int tab[taille];
	printf("Maintenant entrer vos chiffres : \n");
	for(int i = 0; i < taille; i++)
		scanf("%d", &tab[i]);;
	ft_min_max(tab, taille, &min, &max);
	printf("La valeur max %d et la valeur min %d\n", max, min);
	return EXIT_SUCCESS;
}

void ft_min_max(int *tab, int taille, int *adrmin, int *adrmax)
{
	*adrmin = *tab;
	for(int i = 0; i < taille; i++)
	{
		if(*(tab+i) < *adrmin)
			*adrmin = *(tab+i);
		if(*(tab+i) > *adrmax)
			*adrmax = *(tab+i);
	}
}
