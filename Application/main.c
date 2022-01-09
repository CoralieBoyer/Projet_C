/* INCLUDE DES LIBRAIRIES */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gtk/gtk.h>
#include <mysql.h>
//#include <setjmp.h>
#include "hpdf.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


/* STRUCTURES */
typedef struct Item {
    int value;
    struct Item * next;
} IdQuestion;
IdQuestion * start = NULL;

/* VARIABLES GLOBALES */
char userName[255] = "Nom1";
char userFirstName[255] = "Prenom1";
char directory[255] = "";
//gtk.c
int pagePause = 0;
char phrase[255];
int found = 0;
char name[510] = "";
char where[1000]="";
//questions.c
char* var_table;
int i;
int id;
int boolean;
char id_fk[25]="";
char id_element[5]="";
//co_deco_sql.c
MYSQL mysql;
MYSQL_ROW row;
//pdf.c
float x=480;
HPDF_Page page;
HPDF_Font font;
HPDF_Doc  pdf;
char fname[256];
HPDF_Encoder encoding;
//curl.c
char date[20] = "";

/* INCLUDE DES FICHIERS */
#include "co_deco_sql.c"
#include "curl.c"
#include "pdf.c"
#include "my_libsql.c"
#include "ldc.c"
#include "questions.c"
#include "gtk.c"
//Ajouter les fichiers de modif

int main (int argc, char **argv){
  printf("BIENVENUE DANS LE JEU 2vine_ki_C !\n");
  printf("\nAvant de commencer :\n");

  printf("Entrez votre nom de famille (sans espace)\n");
  scanf("%s", userName);

  printf("Entrez votre prenom (sans espace)\n");
  scanf("%s", userFirstName);

  strcat (directory, "./PDF/");
  strcat (directory, userName);
  strcat (directory, userFirstName);

  int status;
  play(status, argc, argv);
  HPDF_Free (pdf);
  return status;
}
