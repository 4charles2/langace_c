#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	char *chaine="A";
	char *chaine2="2";
	//char *dest = malloc(sizeof(chaine) * (strlen(chaine)+strlen(chaine2)));
	strcat(dest, chaine2);
	strcat(dest, chaine);
	printf("%s", dest);


	return EXIT_SUCCESS;
}
