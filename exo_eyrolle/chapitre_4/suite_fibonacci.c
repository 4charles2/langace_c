#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ft_suite_fibonacci(int n);

int main (void)
{
	int resultat = ft_suite_fibonacci(7);
	printf("Le résultat %d", resultat);
	return EXIT_SUCCESS;
}

int ft_suite_fibonacci(int n)
{
	int som = 0, fb = 1;
	if(n<2)
	{
		if(n == 0)
			return 0;
	return 1;;
	}

	for(int i = 2; i <= n; i++)
	{
		som = som + fb;
		fb = ceil(som/2.);
	}

	return som;
}
