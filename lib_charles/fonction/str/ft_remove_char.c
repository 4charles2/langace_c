void ft_remove_char(char *str, char c)
{
	int i = 0, write = 0;
	while(*(str+i))
	{
		if(*(str+i) != c)
			*(str+write++) = *(str+i);;
		i++;;
	}

	*(str+write) = '\0';
}
