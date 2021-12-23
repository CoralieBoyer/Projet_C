#include <gtk/gtk.h>
#include <stdlib.h>
 
int
main(int argc, char *argv [])
{
  GtkWidget *fenetre_principale;
  GtkWidget *box;
  GtkWidget *button;
  GError *error = NULL;
  GtkCssProvider *cssprovider;
  GFile *file;
 
  /* Initialisation de la librairie Gtk. */
  gtk_init(&argc, &argv);
 
  // création de la fenêtre principale
  fenetre_principale =gtk_window_new ( GTK_WINDOW_TOPLEVEL );
  gtk_window_set_title(GTK_WINDOW(fenetre_principale), "Test background");
  gtk_window_set_position(GTK_WINDOW( fenetre_principale ), GTK_WIN_POS_CENTER_ALWAYS);
 
  box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add (GTK_CONTAINER (fenetre_principale), box);
 
  button = gtk_button_new_with_label ("mission impossible");
  gtk_box_pack_start (GTK_BOX (box), button, FALSE, FALSE, 4);
  button = gtk_button_new_with_label ("bouton 2");
  gtk_box_pack_start (GTK_BOX (box), button, FALSE, FALSE, 4);
 
  /* Ajout du css à la fenêtre */
  /* Chargement du css */
  file = g_file_new_for_path ("./theme.css");
  cssprovider = gtk_css_provider_new ();
  if (!gtk_css_provider_load_from_file (cssprovider, file, &error))
    {
      g_printerr ("%s\n", error->message);
      exit (error->code);
    }
  gtk_style_context_add_provider_for_screen (gdk_display_get_default_screen (gtk_widget_get_display (fenetre_principale)), GTK_STYLE_PROVIDER (cssprovider), GTK_STYLE_PROVIDER_PRIORITY_USER);
 
 
 
  // signaux pour la fermeture de l'application
  g_signal_connect(G_OBJECT(fenetre_principale), "delete_event", (GCallback)gtk_main_quit, NULL);
  g_signal_connect(G_OBJECT(fenetre_principale), "destroy",(GCallback)gtk_main_quit, NULL);
 
  gtk_widget_show_all(fenetre_principale);
 
  gtk_main();
 
  g_object_unref (G_OBJECT (cssprovider));
 
  return 0;
}
