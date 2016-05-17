void ft_sort_ascending(int *tab, int size)
{
	int tmp = 0, changement = 1, i = 0;

	while(changement)
		for(i=1, changement = 0;i<size; i++)
		{
			if(*(tab+i) < *(tab+i-1))
			{
				tmp = *(tab+i);
				*(tab+i) = *(tab+(i-1));
					*(tab+(i-1)) = tmp;
				changement = 1;
			}
		};
}
