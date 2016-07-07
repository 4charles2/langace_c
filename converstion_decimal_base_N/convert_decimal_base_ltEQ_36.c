#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Permet de convertir un nombre des base b <= 36
char *tabChiffre = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

char chiffre(int nb);
int nombre(char ch);
int lire_rep(char *rep, int b);

int main (void)
{
	printf("Le résultat = %d\n",lire_rep("101010", 2));
	return EXIT_SUCCESS;
}

int lire_rep(char *rep,int b)
{
	int nb_chiff=strlen(rep);
	int somme=0;
	int b_puiss_i=1;
	int c_i = 0;
	for(int index = 0; index < nb_chiff; index++)
	{
		c_i = rep[nb_chiff - index - 1];
		somme = somme + nombre(c_i) * b_puiss_i;
		b_puiss_i = b_puiss_i * b;
	}
	return somme;
}

char chiffre(int nb)
{
	return tabChiffre[nb];
}

int nombre(char ch)
{
	int index = 0;
	while (tabChiffre[index])
	{
		if (tabChiffre[index] == ch){
			return index;}
		index++;
	}
}
