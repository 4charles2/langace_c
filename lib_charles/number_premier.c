void ft_calcul_nb_premier(int nombre)
{
	int racine = sqrt(nombre), premier = 1, i = 0;
	for( i = 2; i <= racine && premier; i++)
		if(!(nombre%i))
			premier = 0;;

	if(premier)
		printf("C'est un nombre premier\n");
	else
		printf("Le nombre n'est pas premier car il se divise par %d\n", i);

}
