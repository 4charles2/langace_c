#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int c = 1;
	double moyenne = 0;

	for(int note = 0 ; printf("\nnote %d :", c),scanf("%d", &note), note>=0?moyenne+=note:printf("Calcule de la moyenne\n"), note >=0; c++);

	c--;
	printf("moyenne de ces %d notes : %2.3lf", c, moyenne /= c);

	return 0;
}
