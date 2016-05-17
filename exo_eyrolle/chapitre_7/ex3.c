#include <stdio.h>
#include <stdlib.h>

void ft_sort_ascending(int *tab, int size);
int ft_value_min(int *tab, int size);
void ft_show_tab(int *tab);

int main (void)
{
	int tab[10] = {10,20,45,76,8,6,98,4,66,12};
	ft_sort_ascending(tab, 10);
	printf("valeur min : %d\n", ft_value_min(tab, 10));
	ft_show_tab(tab);
	return EXIT_SUCCESS;
}
