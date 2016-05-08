void ft_affiche_table_multiplication(int tableMax)
{
	int i = 0;
	printf("     I");
	for(i = 1; printf("%4d", i), i < tableMax; i++);
	printf("\n------");
	for(i = 1; printf("----"), i < tableMax ; i++);
	for(i = 1; i <= tableMax; i++)
	{
		printf("\n%4d", i);
		printf(" I");
		for(int y = 1; y <= tableMax; y++)
		{
			printf("%4d", y*i);
		}
	}

}
