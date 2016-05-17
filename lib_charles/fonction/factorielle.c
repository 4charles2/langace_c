long ft_factorielle(int facteur)
{
	if (facteur>1) return (ft_factorielle(facteur-1)*facteur);
	else return 1;
}
