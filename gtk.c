#include <gtk/gtk.h>

static void pageJeu (GtkWidget *widget, gpointer data){
  GtkWidget *gameBox = GTK_WIDGET(data);
  GtkWidget *title;

  //TITRE
  title=gtk_label_new("¿2vine ki C?");
  gtk_container_add(GTK_CONTAINER(gameBox), title);

  //AFFICHAGE
  gtk_widget_show_all (gameBox);

}

static void activate (GtkApplication *app, gpointer user_data){
  GtkWidget *window;
  GtkWidget *title;
  GtkWidget *principalBox;
  GtkWidget *homeBox;
  GtkWidget *gameBox;
  GtkWidget *verticalBox;
  GtkWidget *horizontalBox;
  GtkWidget *buttonStart;
  GtkWidget *buttonStart_box;
  GtkWidget *buttonModify;
  GtkWidget *buttonModify_box;
  GtkWidget *logo;

  GtkCssProvider *cssProvider = gtk_css_provider_new();
  gtk_css_provider_load_from_path(cssProvider, "./style.css", NULL);
  gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                               GTK_STYLE_PROVIDER(cssProvider),
                               GTK_STYLE_PROVIDER_PRIORITY_USER);

  //FENETRE
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "2vine ki C");
  gtk_window_set_default_size (GTK_WINDOW (window), 800, 500);

  //BOXE PRINCIPALE
  principalBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 100);
  gtk_container_add(GTK_CONTAINER(window), principalBox);


  //BOXE ACCUEIL
  homeBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 100);
  gtk_container_add(GTK_CONTAINER(principalBox), homeBox);

  //BOXE JEU
  gameBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 100);
  gtk_container_add(GTK_CONTAINER(principalBox), gameBox);


  //TITRE
  title=gtk_label_new("¿2vine ki C?");
  gtk_container_add(GTK_CONTAINER(homeBox), title);

  //BOXE HORIZONTALE
  horizontalBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 100);
  gtk_container_add(GTK_CONTAINER(homeBox), horizontalBox);

  //LOGO
  logo = gtk_image_new_from_file ("./logo.jpeg");
  gtk_container_add(GTK_CONTAINER(horizontalBox), logo);

  //BOXE VERTICAL
  verticalBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 30);
  gtk_container_add(GTK_CONTAINER(horizontalBox), verticalBox);

  //BOUTON JOUER
  buttonStart_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (verticalBox), buttonStart_box);

  buttonStart = gtk_button_new_with_label ("JOUER");
  g_signal_connect (buttonStart, "clicked", G_CALLBACK (pageJeu), (gpointer)gameBox);
  g_signal_connect_swapped (buttonStart, "clicked", G_CALLBACK (gtk_widget_destroy), homeBox);
  gtk_container_add (GTK_CONTAINER (buttonStart_box), buttonStart);

  //BOUTON MODIFIER
  buttonModify_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (verticalBox), buttonModify_box);

  buttonModify = gtk_button_new_with_label ("MODIFIER");
  g_signal_connect (buttonModify, "clicked", G_CALLBACK (pageJeu), NULL); //APPELLE PAS LA BONNE FONCTION
  g_signal_connect_swapped (buttonModify, "clicked", G_CALLBACK (gtk_widget_destroy), window);
  gtk_container_add (GTK_CONTAINER (buttonModify_box), buttonModify);

  //AFFICHAGE
  gtk_widget_show_all (window);
}

int main (int argc, char **argv){
  GtkApplication *app;
  int status;

  app = gtk_application_new (NULL, G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
