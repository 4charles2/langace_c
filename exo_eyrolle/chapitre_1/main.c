#include <stdio.h>
#include <stdlib.h>

#define put_string(x,i) while((x)[i] != '\0') {putc((x)[i++], stdout);}

void videBuffer();

int main(void)
{
	char msg[] = "Appuyer sur une touche pour continuer";
	int i = 0;

	put_string(msg, i);
	putchar('\n');

	return 0;
}

void videBuffer()
{
	int c;

	while(c != '\n' && c != EOF)
		c = getchar();

}
