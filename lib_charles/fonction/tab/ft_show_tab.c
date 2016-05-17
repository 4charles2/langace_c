#include <stdio.h>
void ft_show_tab(int *tab)
{
	int i = 0;
	while(*(tab+i++))
		printf("%d ", *(tab+i-1));
}
