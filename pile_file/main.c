#include <stdio.h>
#include <stdlib.h>
#include "libfile.a"

int main(void)
{
	File *myFile = initialiser();

	remplirFile(myFile, 4);
	remplirFile(myFile, 8);
	remplirFile(myFile, 15);
	remplirFile(myFile, 16);
	remplirFile(myFile, 32);
	remplirFile(myFile, 42);

	afficherFile(myFile);

	defiler(myFile);
	defiler(myFile);

	afficherFile(myFile);

	return 0;
}
