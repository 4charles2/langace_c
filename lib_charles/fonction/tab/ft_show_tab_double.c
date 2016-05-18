#include <stdio.h>

void ft_show_tab_double(double *tab)
{
	int i = 0;
	while(*(tab+i++))
		printf("%.2f ", *(tab+i-1));;
}
