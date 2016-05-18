#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"

void ft_conjugate_french_verb_first_group(char *str);

int main (int argc, char **argv)
{
	if(argc < 2 && !strcmp(argv[1]+ft_strlen(argv[1])-2, "er"))
	{
		printf("Vous n'avez pas rentrez de verbe du premier groupe ou pas de verbe");
		return 0;
	}


	char *str = (char*) malloc(sizeof(*str) * ft_strlen(argv[1]));
	ft_conjugate_french_verb_first_group(argv[1]);
	free(str);
	return 1;
}

void ft_conjugate_french_verb_first_group(char *str)
{
	int size = ft_strlen(str);
	char *term[6] = {"e", "es", "e", "ons", "ez", "ent"};
	char *deb[6] = {"je", "tu", "il", "nous", "vous", "ils"};
	
}
