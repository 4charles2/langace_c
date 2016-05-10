#include <stdio.h>
#include <stdlib.h>

int ft_ackermann(int n, int m);

int main (void)
{
	int A = ft_ackermann(4, 0);
	printf("%d", A);
		return EXIT_SUCCESS;
}

int ft_ackermann(int n, int m)
{
	if(n<0 || m<0)
		return 0;
	else if (m == 0)
		return (n+1);
	else if (n == 0)
		return (ft_ackermann(m-1, 1));
	else
		return (ft_ackermann(m-1,ft_ackermann(m, n-1)));
	
}
