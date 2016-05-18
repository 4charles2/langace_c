#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

static void ft_som_tab(double *tab1, double *tab2, double *som, int size);
static void ft_show_tab(double *tab, int size);

int main (void)
{
	double tab1[SIZE] = {2.4,43.4,6.6,46.8,89.9,54.6,23.3,19.6,34.6,23.7};
	double tab2[SIZE] = {3,64,75,23,24,45,76,34,34,89};
	double answer[SIZE] = {0};
	ft_som_tab(tab1, tab2, answer, SIZE);
	ft_show_tab(answer, SIZE);

	return EXIT_SUCCESS;
}

static void ft_som_tab(double *tab1, double *tab2, double *som, int size)
{
	while(--size >= 0)
		*(som+size) += *(tab1+size) + *(tab2+size);;
		
}


static void ft_show_tab(double *tab, int size)
{
	int i = 0;
	while(i < size)
		printf("%.2f \n", *(tab+i++));;

}
