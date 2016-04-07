#include <stdlib.h>
#include <gtk/gtk.h>

int main(int argc, char **argv)
{

	gtk_init(&argc,&argv);

	GtkWidget* label = NULL;
	GtkWidget* MainWindow = NULL;

	MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	/*initialisation du label*/
	label = gtk_label_new("Le jeu du Pendu");

	g_signal_connect(G_OBJECT(MainWindow), "delete-event", G_CALLBACK(gtk_main_quit), NULL);

	gtk_window_set_title(GTK_WINDOW(MainWindow), "Jeu du pendu");

	gtk_window_set_default_size(GTK_WINDOW(MainWindow), 800, 500);
	gtk_window_set_position(GTK_WINDOW(MainWindow), GTK_WIN_POS_CENTER_ALWAYS);
	gtk_window_set_icon_from_file(GTK_WINDOW(MainWindow), "pendu.ico", NULL);
	/*bouton fermer*/
	gtk_window_set_deletable(GTK_WINDOW(MainWindow), TRUE);

	/*dfinition des bordure de la fenetre*/
	gtk_window_set_frame_dimensions(GTK_WINDOW(MainWindow), 50,50,50,50);


	/*Rajouter notre label dans la fenetre */
	gtk_container_add(GTK_CONTAINER(MainWindow), label);

	/*Pour afficher tous les widgets dans la fenetre*/
	gtk_widget_show_all(MainWindow);
	gtk_main();

	return EXIT_SUCCESS;
}

/*Si je veux modifier le label*/
/*const variable = gtk_label_set_label(label, "La modification");
Pour aligner le texte soit à droite ou a gauche ALIGNEMENT
void gtk_label_set_justify(label, JType);
Les JType : GTK_JUSTIFY_LEFT Pour aligner le texte à gauche
