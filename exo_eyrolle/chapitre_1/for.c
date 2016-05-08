#include <stdio.h>
#include <stdlib.h>

#define put_string(x,i) while((x)[i] != '\0') {putc((x)[i++], stdout);}

void videBuffer();

int main(void)
{
	int i = 0;
	for(i = 0, printf("commence");printf("debut de tour\n"), i < 10; printf("fin de tour\n"), i++);

	return 0;
}

void videBuffer()
{
	int c;
	while((c = getchar()) != '\n' && c != EOF);
}
