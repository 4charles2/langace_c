#include <stdio.h>
#include <stdlib.h>

void ft_min_max_formalisme_tab(int *tab, int taille);
void ft_min_max_formalisme_pointeur(int *tab, int taille);

int main (void)
{
	int tab[10] = {0};
	for(int i = 0; i < 10; i++)
		scanf("%d", &tab[i]);

	ft_min_max_formalisme_tab(tab, 10);
	ft_min_max_formalisme_pointeur(tab, 10);
	return EXIT_SUCCESS;
}

void ft_min_max_formalisme_tab(int *tab, int taille)
{
	int min = tab[0], max = tab[0];
	for(int i = 0; i < taille; i++)
	{
		if(tab[i] < min)
			min = tab[i];
		if(tab[i] > max)
			max = tab[i];
	}
	printf("min : %d max : %d facon tableau\n", min, max);
}

void ft_min_max_formalisme_pointeur(int *tab, int taille)
{
	int min = *tab, max = *tab;
	for(int i = 0; i < taille; i++)
	{
		if(*(tab+i) < min)
			min = *(tab+i);
		if(*(tab+i) > max)
			max = *(tab+i);
	}
	printf("min : %d max : %d facon pointeur\n", min, max);
}
