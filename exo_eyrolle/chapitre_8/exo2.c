#include <stdio.h>
#include "str.h"

void ft_remove_char(char *str, char c);

int main (void)
{
	char str[32];
	ft_putstr("Entrez une phrase: ");
	while(!fgets(str, 32, stdin))
		ft_putstr("Vous n'avez pas rentrer une bonne phrase !");;

	ft_remove_char(str, 'e');
	ft_putstr(str);
	return 1;
}

void ft_remove_char(char *str, char c)
{
	int i = 0, write = 0;
	while(*(str+i))
	{
		if(*(str+i) != c)
			*(str+write++) = *(str+i);;
		i++;
	}

	*(str+write) = '\0';
}
