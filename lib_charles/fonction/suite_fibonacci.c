int ft_suite_fibonacci(int n)
{
	int som = 1, fb = 1;
	if(n<2)
	{
		if(n == 0)
			return 0;
	return 1;;
	}

	for(int i = 2; i <= n; i++)
	{
		fb = som - fb;
		som += fb;
		
	}

	return som;
}
