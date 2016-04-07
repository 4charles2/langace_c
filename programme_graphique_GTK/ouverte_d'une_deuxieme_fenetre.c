#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

void secondFenetre(GtkWidget* MainWindow);
void mafonction(GtkWidget *widget, gpointer data);

void secondFenetre(GtkWidget* MainWindow)
{
	GtkWidget* SecondWindow = NULL;
	GtkWidget* label = NULL;
	const gchar* titre = NULL;

	SecondWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	titre = gtk_window_get_title(GTK_WINDOW(MainWindow));

	label = gtk_label_new(titre);
	gtk_container_add(GTK_CONTAINER(SecondWindow), label);

	gtk_window_set_position(GTK_WINDOW(SecondWindow), GTK_WIN_POS_CENTER_ALWAYS);
	gtk_window_set_default_size(GTK_WINDOW(SecondWindow), 800, 500);
	gtk_window_set_title(GTK_WINDOW(SecondWindow), "HaHaHAHAHA");
	gtk_widget_show_all(SecondWindow);
	g_signal_connect(G_OBJECT(SecondWindow), "delete-event", G_CALLBACK(mafonction), NULL);
}
void mafonction(GtkWidget *widget, gpointer data)
{
	gtk_main_quit();
}

int main(int argc, char **argv)
{
	/* Variables */
	GtkWidget * MainWindow = NULL;
	const gchar* titre = NULL;
	int taille = 0;

	/* Initialisation de GTK+ */
	gtk_init(&argc, &argv);

	/* Création de la fenêtre */
	MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	/*creation du titre de la fenetre*/
	gtk_window_set_title(GTK_WINDOW(MainWindow), "Titre de la fenetre");
	titre = gtk_window_get_title(GTK_WINDOW(MainWindow));
	g_signal_connect(G_OBJECT(MainWindow), "delete-event", G_CALLBACK(secondFenetre), NULL);

	taille = strlen(titre);

	while(taille >= 0)
	{
		printf("%c", titre[taille]);
		taille--;
	}
	/* Affichage et boucle événementielle */
	gtk_widget_show_all(MainWindow);
	gtk_main();
	/* Fermeture de GTK+ */
	gtk_exit(EXIT_SUCCESS);
	return EXIT_SUCCESS;
}

