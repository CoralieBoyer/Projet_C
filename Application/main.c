/* INCLUDE DES LIBRAIRIES */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gtk/gtk.h>
#include <mysql.h>
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
int ok;
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

/* DEBUT DU PROGRAMME */
void beforeStarting();

int main (int argc, char **argv){
  int status;

  connect_bdd();

  beforeStarting();
  play(status, argc, argv);

  close_mysql();

  return status;
}
