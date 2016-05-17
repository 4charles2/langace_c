/* liste_chaine.h pour fichier liste_chaine.c
Construit pour libcharles
Par Charles le 22/04/210*/
/*il faut faire un pointeur de struct llist typedef NAME_STRUCT* llist*/
#ifndef __LISTE_CHAINE__
#define __LISTE_CHAINE__
llist ft_add_onset(llist first, int nvValeur);/*Ajoute en debut de liste*/
llist ft_add_ending(llist first, int nvValeur);/*Ajoute en fin de liste*/
llist ft_del_onset(llist first);/*supression premier element de la liste*/
llist ft_del_offset(llist first);/*supression dernier element de la liste*/
int ft_list_fill_or_void(llist first);/*vérifie si la liste n'est pas vide renvoie 0 si vide et 1 si rempli*/
int ft_search_nb_occurence(int value, llist first);/*chercher occurence d'une valeur*/
int ft_count_element(llist first);/*Compte le nombre d'élement*/
void ft_show_liste(llist first);/*Affiche toutes les valeurs de la liste*/
llist ft_search_value_list(llist first, int value);
#endif
