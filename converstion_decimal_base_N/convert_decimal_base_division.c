#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Permet de convertir un nombre des base b <= 36
char *tabChiffre = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

char chiffre(int nb);
int nombre(char ch);
int lire_rep(char *rep, int b);
char *repr_nombre(int n, int b);

int main (void)
{
	//Convertir binaire en decimal
	printf("Le résultat = %d\n",lire_rep("101010", 2));
	//Convertir un nombre decimal en base préciser
	printf("Le résultat = %s\n", repr_nombre(42, 16));
	return EXIT_SUCCESS;
}

char *repr_nombre(int n, int  b)
{
	//Avec des division euclidienne
	char *rep = malloc(sizeof(char));
	char *tmp;
	int q = n;
	int r = 0;
	int index = 0;
	while(q!=0)
	{
		r = q%b;
		if(!realloc(rep, strlen(rep)+1)){
			printf("erreur realloc");
		}
		tmp = malloc(sizeof(char) * strlen(rep));
		strcat(tmp, rep);
		rep[0] = chiffre(r);
		strcat(rep, tmp);
		free(tmp);
		q = q/b;
	}
	return rep;
}

int lire_rep(char *rep,int b)
{
	//Avec les puissance
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
