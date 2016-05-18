#include <stdio.h>
#include "str.h"

void ft_reverse_string(char *str);

int main (void)
{
	ft_reverse_string("Ma phrase a l'envers");
	return 1;
}

void ft_reverse_string(char *str)
{
	int size = ft_strlen(str);
	while(size-- >= 0)
		ft_putchar(*(str+size));
}
