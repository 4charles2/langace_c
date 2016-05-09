#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void essai(int nbARG, ...);

int main (void)
{
	printf("premier essai\n");
	essai(5, 125, 15, 30, 40);
		return EXIT_SUCCESS;
}

void essai(int nbARG, ...)
{
	va_list adpar;
	int parv, i = 0;
	va_start(adpar, nbARG);
	for(i=1; i < nbARG; i++)
	{
		parv = va_arg(adpar, int);
		printf("argument variable : %d\n", parv);
	}

	va_end(adpar);
}
