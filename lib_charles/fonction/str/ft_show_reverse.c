void ft_show_reverse(char *str)
{
	int size = ft_strlen(str);
	while(size-- >= 0)
		ft_putchar(*(str+size));
}
