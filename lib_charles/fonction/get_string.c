int get_string(char *chaine, int size)
{
	char *positionEntree = NULL;

	if(fgets(chaine, size, stdin) != NULL)
	{
		positionEntree = strchr(chaine, '\n');
		if(positionEntree != NULL)
		{
			*positionEntree = '\0';
		}
		else
		{
			viderBuffer();
		}
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
