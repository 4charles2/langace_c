#include <stdio.h>
#include <stdlib.h>

double (*afficheMenu(void))(double, double);
double addition(double n1, double n2);
double soustraction(double n1, double n2);
double multiplication(double n1, double n2);
double division(double n1, double n2);

double addition(double n1, double n2)
{
	return n1 + n2;
}

double soustraction(double n1, double n2)
{
	return n1 - n2;
}

double multiplication(double n1, double n2)
{
	return n1 * n2;
}

double division(double n1, double n2)
{
	return n1 / n2;
}

double (*listeFonctions[4])(double,double) = {addition,soustraction,multiplication,division};

double (* afficheMenu(void))(double, double)
{
	int choix = 0;
	do{
		printf("------------------------------MENU------------------------------\n");
		printf("Veuillez choisir une opération (en choisissant un nombre entre 1 et 4) :\n");
		printf("1 pour addition\n");
		printf("2 pour soustraction\n");
		printf("3 pour multiplication\n");
		printf("4 pour division\n");
		printf("Faite votre choix : ");
		scanf("%d", &choix);

	}while(choix < 1 || choix > 4);

	return listeFonctions[choix - 1];
}

int main(void)
{
	double (*fonctionDeCalcul)(double,double);
	double n1,n2;

	fonctionDeCalcul = afficheMenu();

	printf("Saisissez les opérandes : ");
	scanf("%lf", &n1);
	scanf("%lf", &n2);

	printf("le resultat du calcul est : %f\n",(*fonctionDeCalcul)(n1,n2));

	return 0;
}
