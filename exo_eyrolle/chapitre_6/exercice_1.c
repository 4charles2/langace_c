#include <stdio.h>
#include <stdlib.h>

void ft_put(void);
void ft_putx(int c);
int ft_intputx(int c);

int main (void)
{
	ft_put();
	ft_putx(5);
	int lvalue = ft_intputx(5);
	printf("%d", lvalue);
		return EXIT_SUCCESS;
}

int ft_intputx(int nb)
{
	int i = 0;
	while(printf("Bonjour %d\n", i),++i < nb);
	return 0;
}

void ft_putx(int nb)
{
	int i = 0;
	while(printf("Bonjour %d\n", i),++i < nb);
}
void ft_put()
{
	printf("Bonjour\n");
}
