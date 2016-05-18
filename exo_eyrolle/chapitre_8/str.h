#ifndef __STR__
#define __STR__
void ft_putchar(char c);
int ft_putnbr(int nb);
void ft_putstr(char *str);
int ft_strlen(char *str);
void ft_put_str_fd(char *str, int fd);/* fd = file descriptor en numerique soit (0 = stdin, 1 = stdout, 2 = stderr)*/
int ft_number_occurence(char *str, char c);
void ft_remove_char(char *str, char c);/* suprime les caracteres designé dans la chaine elle même*/
void ft_show_reverse(char *str);/*Affiche la string reverse sans la modifie*/
#endif
