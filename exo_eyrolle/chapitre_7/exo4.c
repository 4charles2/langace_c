#include <stdio.h>
#include <stdlib.h>

void ft_som_tab(double *tab1, double *tab2, double *som, int size);
void ft_show_tab(double *tab);

int main (void)
{
	double tab1[10] = {2.4,43.4,6.6,46.8,89.9,54.6,23.3,19.6,34.6,23.7};
	double tab2[10] = {3,64,75,23,24,45,76,34,34,89};
	double answer[10];
	ft_som_tab(tab1, tab2, answer, 10);
	ft_show_tab(answer);

	return EXIT_SUCCESS;
}

void ft_som_tab(double *tab1, double *tab2, double *som, int size)
{
	while(--size)
	{
		*(som+size) += *(tab1+size) + *(tab2+size);
	}
}


void ft_show_tab(double *tab)
{
	int i = 0;
	while(*(tab+i++))
		printf("%.2f ", *(tab+i-1));;
}
