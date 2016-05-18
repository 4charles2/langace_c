#include <stdio.h>
#include <stdlib.h>
#include "str.h"

void ft_conjugate_french_verb_first_group(char *str);

int main (int argc, char **argv)
{
	if(argc < 2)
		return 0;

	char *str = (char*) malloc(sizeof(*str) * ft_strlen(argv[1]));
	ft_conjugate_french_verb_first_group(argv[1]);
	free(str);
	return 1;
}

void ft_conjugate_french_verb_first_group(char *str)
{
	int size = ft_strlen(str);
	str[size-1] = '\0';
	ft_putstr("je ");
	ft_putstr(str);
	ft_putstr("\ntu ");
	ft_putstr(str);
	ft_putstr("s");
	ft_putstr("\nil ");
	ft_putstr(str);
	*(str+size-2) = '\0';
	ft_putstr("\nnous ");
	ft_putstr(str);
	ft_putstr("ons");
	*(str+size-2) = 'e';
	ft_putstr("\nvous ");
	ft_putstr(str);
	ft_putstr("z");
	ft_putstr("\nils ");
	ft_putstr(str);
	ft_putstr("nt\n");
	*(str+size-1) = 'r';/*Verbe remit à l'infinitif*/
}
