#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

void showCaractereInLabel(GtkWidget* MainWindow, gpointer data);
void mafonction(GtkWidget *widget, gpointer data);

void showCaractereInLabel(GtkWidget* MainWindow, gpointer data)
{
	GtkWidget* label = NULL;
	gchar prenom = NULL;
	int i = 0;
	gchar *name = "charles";
	prenom[0] = name[i];
	i++;
	/*Création du label*/
	label = gtk_label_new("coucou");
	gtk_container_add(GTK_CONTAINER(MainWindow), label);
	gtk_label_set(GTK_LABEL(label), prenom);
	gtk_widget_show_all(MainWindow);

}
void mafonction(GtkWidget *widget, gpointer data)
{
	gtk_main_quit();
}

int main(int argc, char **argv)
{
	/* Variables */
	GtkWidget* MainWindow = NULL;

	/* Initialisation de GTK+ */
	gtk_init(&argc, &argv);

	/* Création de la fenêtre */
	MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	/*creation du titre de la fenetre*/
	gtk_window_set_title(GTK_WINDOW(MainWindow), "Titre de la fenetre");
	g_signal_connect(G_OBJECT(MainWindow), "delete-event", G_CALLBACK(showCaractereInLabel), NULL);
	gtk_window_set_default_size(GTK_WINDOW(MainWindow), 800, 500);
	gtk_window_set_position(GTK_WINDOW(MainWindow), GTK_WIN_POS_CENTER_ALWAYS);

	/* Affichage et boucle événementielle */
	gtk_widget_show_all(MainWindow);
	gtk_main();
	/* Fermeture de GTK+ */
	gtk_exit(EXIT_SUCCESS);
	return EXIT_SUCCESS;
}

