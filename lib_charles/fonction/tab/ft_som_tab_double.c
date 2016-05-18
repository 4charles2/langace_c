#include <stdio.h>

void ft_som_tab(double *tab1, double *tab2, double *som, int size)
{
	while(--size)
	{
		*(som+size) += *(tab1+size) + *(tab2+size);
	}
}
