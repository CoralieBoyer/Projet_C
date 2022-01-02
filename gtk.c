#include <gtk/gtk.h>
#include "main.c"
#include "questions.c"
#include "co_deco_sql.c"

//var
//int* var_table;
int pagePause = 0;
char phrase[255];

//proto
static void gameWindow (GtkWidget *widget, gpointer data);
static void homeWindow (GtkWidget *widget, gpointer data);

//func

static void pauseWindow (GtkWidget *widget, gpointer data){
  GtkWidget *window = GTK_WIDGET(data);
  GtkWidget *principalBox;
  GtkWidget *horizontalBox;
  GtkWidget *logo;
  GtkWidget *verticalBox;
  GtkWidget *buttonResume;
  GtkWidget *buttonResume_box;
  GtkWidget *buttonQuit;
  GtkWidget *buttonQuit_box;
  GtkWidget *title;

  pagePause = 1;

  //BOXE PRINCIPALE
  principalBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 100);
  gtk_container_add(GTK_CONTAINER(window), principalBox);
  gtk_widget_set_margin_top(principalBox,100);

  //BOXE HORIZONTALE
  horizontalBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 100);
  gtk_container_add(GTK_CONTAINER(principalBox), horizontalBox);

  //LOGO
  logo = gtk_image_new_from_file ("./logo.jpeg");
  gtk_container_add(GTK_CONTAINER(horizontalBox), logo);
  gtk_widget_set_margin_start(logo,100);

  //BOXE VERTICALE
  verticalBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
  gtk_container_add(GTK_CONTAINER(horizontalBox), verticalBox);

  //BOUTON REPRENDRE
  buttonResume_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (verticalBox), buttonResume_box);
  gtk_widget_set_margin_top(buttonResume_box,50);

  buttonResume = gtk_button_new_with_label ("Reprendre");
  g_signal_connect (buttonResume, "clicked", G_CALLBACK (gameWindow), (gpointer)window);
  g_signal_connect_swapped (buttonResume, "clicked", G_CALLBACK (gtk_widget_destroy), principalBox);
  gtk_container_add (GTK_CONTAINER (buttonResume_box), buttonResume);
  gtk_widget_set_size_request(buttonResume,300,50);

  //BOUTON QUITTER
  buttonQuit_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (verticalBox), buttonQuit_box);

  buttonQuit = gtk_button_new_with_label ("Quitter");
  g_signal_connect (buttonQuit, "clicked", G_CALLBACK (homeWindow), (gpointer)window);
  g_signal_connect (buttonQuit, "clicked", G_CALLBACK (free_variable), NULL);
  g_signal_connect_swapped (buttonQuit, "clicked", G_CALLBACK (gtk_widget_destroy), principalBox);
  gtk_container_add (GTK_CONTAINER (buttonQuit_box), buttonQuit);
  gtk_widget_set_size_request(buttonQuit,300,50);

  //TITRE
  title=gtk_label_new("¿2vine ki C?");
  gtk_container_add(GTK_CONTAINER(principalBox), title);
  gtk_widget_set_margin_top(title,10); //AJOUT DE MARGE EN HAUT
//  gtk_widget_set_size_request(title,300,50); //TAILLE

  gtk_widget_show_all(principalBox);
}

static void gameWindow (GtkWidget *widget, gpointer data){
  GtkWidget *window = GTK_WIDGET(data);
  GtkWidget *principalBox;
  GtkWidget *horizontalBox;
  GtkWidget *verticalBoxLeft;
  GtkWidget *verticalBoxRight;
  GtkWidget *question;
  GtkWidget *buttonYes_box;
  GtkWidget *buttonYes;
  GtkWidget *buttonNo_box;
  GtkWidget *buttonNo;
  GtkWidget *logo;
  GtkWidget *buttonPause_box;
  GtkWidget *buttonPause;

  if(pagePause == 0)
    printf_question(phrase);

  pagePause = 0;

  //BOXE PRINCIPALE
  principalBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 100);
  gtk_container_add(GTK_CONTAINER(window), principalBox);

  //BOXE HORIZONTALE
  horizontalBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 100);
  gtk_container_add(GTK_CONTAINER(principalBox), horizontalBox);
  gtk_widget_set_margin_top(horizontalBox,50); //AJOUT DE MARGE EN HAUT

  //BOXE VERTICAL GAUCHE
  verticalBoxLeft = gtk_box_new(GTK_ORIENTATION_VERTICAL, 30);
  gtk_container_add(GTK_CONTAINER(horizontalBox), verticalBoxLeft);
  gtk_widget_set_margin_top(verticalBoxLeft,50); //AJOUT DE MARGE EN HAUT
  gtk_widget_set_margin_start(verticalBoxLeft,150); //AJOUT DE MARGE A GAUCHE

  //BOXE VERTICAL DROITE
  verticalBoxRight = gtk_box_new(GTK_ORIENTATION_VERTICAL, 30);
  gtk_container_add(GTK_CONTAINER(horizontalBox), verticalBoxRight);
  gtk_widget_set_margin_start(verticalBoxRight,75); //AJOUT DE MARGE A GAUCHE

  //QUESTION
  question=gtk_label_new(phrase);
  gtk_container_add(GTK_CONTAINER(verticalBoxLeft), question);

  //BOUTON REPONSE OUI
  buttonYes_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (verticalBoxLeft), buttonYes_box);

  buttonYes = gtk_button_new_with_label ("OUI");
  g_signal_connect (buttonYes, "clicked", G_CALLBACK (response_yes), NULL);
  g_signal_connect (buttonYes, "clicked", G_CALLBACK (gameWindow), (gpointer)window);
  g_signal_connect_swapped (buttonYes, "clicked", G_CALLBACK (gtk_widget_destroy), principalBox);
  gtk_container_add (GTK_CONTAINER (buttonYes_box), buttonYes);

  //BOUTON REPONSE NON
  buttonNo_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (verticalBoxLeft), buttonNo_box);

  buttonNo = gtk_button_new_with_label ("NON");
  g_signal_connect (buttonNo, "clicked", G_CALLBACK (gameWindow), (gpointer)window);
  g_signal_connect_swapped (buttonNo, "clicked", G_CALLBACK (gtk_widget_destroy), principalBox);
  gtk_container_add (GTK_CONTAINER (buttonNo_box), buttonNo);

  //LOGO
  logo = gtk_image_new_from_file ("./logo.jpeg");
  gtk_container_add(GTK_CONTAINER(verticalBoxRight), logo);

  //BOUTON PAUSE
  buttonPause_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (verticalBoxRight), buttonPause_box);

  buttonPause = gtk_button_new_with_label ("||");
  g_signal_connect (buttonPause, "clicked", G_CALLBACK (pauseWindow), (gpointer)window);
  g_signal_connect_swapped (buttonPause, "clicked", G_CALLBACK (gtk_widget_hide), principalBox);
  gtk_container_add (GTK_CONTAINER (buttonPause_box), buttonPause);

  gtk_widget_show_all(principalBox);
}

static void close_window (GtkWidget *widget, gpointer data){
  GtkWidget *window = GTK_WIDGET(data);
//  gtk_widget_hide(window);
  modifyWindow();
}

static void homeWindow (GtkWidget *THEwindow, gpointer data){
  GtkWidget *window = GTK_WIDGET(data);
  GtkWidget *title;
  GtkWidget *principalBox;
  GtkWidget *verticalBox;
  GtkWidget *horizontalBox;
  GtkWidget *buttonStart;
  GtkWidget *buttonStart_box;
  GtkWidget *buttonModify;
  GtkWidget *buttonModify_box;
  GtkWidget *logo;

  //BOXE PRINCIPALE
  principalBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 100);
  gtk_container_add(GTK_CONTAINER(window), principalBox);

  //TITRE
  title=gtk_label_new("¿2vine ki C?");
  gtk_container_add(GTK_CONTAINER(principalBox), title);
  gtk_widget_set_margin_top(title,10); //AJOUT DE MARGE EN HAUT
//  gtk_widget_set_size_request(title,300,50); //TAILLE

  //BOXE HORIZONTALE
  horizontalBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 100);
  gtk_container_add(GTK_CONTAINER(principalBox), horizontalBox);
  gtk_widget_set_margin_start(horizontalBox,100); //AJOUT DE MARGE A GAUCHE

  //LOGO
  logo = gtk_image_new_from_file ("./logo.jpeg");
  gtk_container_add(GTK_CONTAINER(horizontalBox), logo);

  //BOXE VERTICAL
  verticalBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 30);
  gtk_container_add(GTK_CONTAINER(horizontalBox), verticalBox);
  gtk_widget_set_margin_top(verticalBox,60); //AJOUT DE MARGE EN HAUT

  //BOUTON JOUER
  buttonStart_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (verticalBox), buttonStart_box);

  buttonStart = gtk_button_new_with_label ("JOUER");
  g_signal_connect (buttonStart, "clicked", G_CALLBACK (malloc_variable), NULL);
  g_signal_connect (buttonStart, "clicked", G_CALLBACK (gameWindow), (gpointer)window);
  g_signal_connect_swapped (buttonStart, "clicked", G_CALLBACK (gtk_widget_destroy), principalBox);
  gtk_container_add (GTK_CONTAINER (buttonStart_box), buttonStart);
  gtk_widget_set_size_request(buttonStart,300,50);

  //BOUTON MODIFIER
  buttonModify_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (verticalBox), buttonModify_box);

  buttonModify = gtk_button_new_with_label ("MODIFIER");
  g_signal_connect (buttonModify, "clicked", G_CALLBACK (close_window), THEwindow);
//  g_signal_connect (buttonModify, "clicked", G_CALLBACK (modifyWindow), NULL);
  gtk_container_add (GTK_CONTAINER (buttonModify_box), buttonModify);
  gtk_widget_set_size_request(buttonModify,300,50);

  gtk_widget_show_all(principalBox);
}

static void activate (GtkApplication *app, gpointer user_data){
  GtkWidget *window;
  GtkWidget *box;

  //FENETRE
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "2vine ki C");
  gtk_window_set_default_size (GTK_WINDOW (window), 800, 500);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

//  GtkCssProvider *cssProvider = gtk_css_provider_new();
//  gtk_css_provider_load_from_path(cssProvider, "./style.css", NULL);
//  gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
//                               GTK_STYLE_PROVIDER(cssProvider),
//                               GTK_STYLE_PROVIDER_PRIORITY_USER);


  //BOX
  box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 100);
  gtk_container_add(GTK_CONTAINER(window), box);


  gtk_widget_show(window);
  gtk_widget_show(box);

  homeWindow(window,box);
}

int main (int argc, char **argv){
  connect_bdd();

  GtkApplication *app;
  int status;

  app = gtk_application_new (NULL, G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  close_mysql();
  return status;
}
