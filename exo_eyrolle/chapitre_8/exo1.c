#include <stdio.h>
#include "str.h"

int main (void)
{
	char str[32];
	puts("Entrez une chaine de caractere");
	while(!fgets(str, 32, stdin))
		ft_putstr("Vous n'avez pas entrer une phrase correct Veuillez recommencer");;

	ft_putnbr(ft_number_occurence(str, 'e'));
	ft_putchar('\n');
	ft_putnbr(ft_strlen(str));
	
	return 1;
}
