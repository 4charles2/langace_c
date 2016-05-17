void ft_putnbr(int nb)
{
	char c = ' ';
	int multiplicateur = 1, unite = nb, nb_dizaine = 0, i = 0;
	if(nb/10 < 1)
	{
		c = nb+48;
		ft_putchar(c);
	}
	else
	{
		while(unite > 10)
		{
			unite /= 10;
			nb_dizaine++;
		}
		while(i++ <= nb_dizaine)
		{
			multiplicateur *= 10;
		}
		while(multiplicateur)
		{
			c = nb/multiplicateur + 48;
			ft_putchar(c);
			multiplicateur /= 10;
		}
	}
}
