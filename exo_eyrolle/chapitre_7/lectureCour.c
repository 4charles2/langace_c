#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int note[20], noteSupMoy = 0;
	double moy = 0;
	for(int i=0; i < 20; i++)
	{
		scanf("%d", &note[i]);
		moy += note[i];
	}
	moy /= 20;
	for(int i = 0; i < 20; i++)
		if(note[i] > moy) noteSupMoy++;

printf("Le nombre de note au dessus de la moyenne (qui et de %f ) est : %d", moy, noteSupMoy);
	return EXIT_SUCCESS;
}
