int ft_strlen(char *str)
{
	int i = 0;
	while(str[i++] != '\n' && str[i] != '\0');

	return i;
}