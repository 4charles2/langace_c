#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void essai(int par1, char par2, ...);

int main (void)
{
	printf("premier essai\n");
	essai(125,'a', 15, 30, 40, -1);
	printf("\ndeuxième essai\n");
	essai(6264,'S', -1);
		return EXIT_SUCCESS;
}

void essai(int par1, char par2, ...)
{
	va_list adpar;
	int parv;
	printf("premier paramètre : %d\n", par1);
	printf("second paramètre: %c\n", par2);
	va_start(adpar, par2);
	while((parv = va_arg(adpar, int)) != -1)
		printf("argument variable : %d\n", parv);

	va_end(adpar);
}
