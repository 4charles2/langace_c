int ft_value_min(int *tab, int size)
{
	int min = *tab;
	for(int i=0;i<size; i++)
	{
		if(*(tab+i) < min)
			min = *(tab+i);
	}
	return min;
}
