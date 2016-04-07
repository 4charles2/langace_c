double get_number_double(char *number, int size)
{
	if(get_string(number, int size)
		return strtod(number, NULL);
	else
		return 0;
}

long get_number_long(char *number, int size)
{
	if(get_string(number, size))
		return strtol(number, NULL, 10);
		/*strtol renvoie un long est 10 signifie que c'est en log10*/
	else
		return 0;
}


int get_string(char *chaine, int size)
{
	char *positionEntree = NULL;

	if(fgets(chaine, size, stdin) != NULL)
	{
		positionEntree = strchr(chaine, '\n');
		if(positionEntree != NULL)
			*positionEntree = '\0';
		else
			viderBuffer();

		return 1;
	}
	else
	{
			viderBuffer();
			return 0;
	}
}

void viderBuffer()
{
	int = c;

	while((c = getchar()) != '\n' && c != EOF);
}
