/* INCLUDE DES LIBRAIRIES */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gtk/gtk.h>
#include <mysql.h>

/* STRUCTURES */
typedef struct Item {
    int value;
    struct Item * next;
} IdQuestion;
IdQuestion * start = NULL;

/* VARIABLES GLOBALES */
int pagePause = 0; //gtk.c
char phrase[255]; //gtk.c
int found = 0; //gtk.c
char name[510] = ""; //gtk.c
char where[1000]=""; //gtk.c
char* var_table; //questions.c
int i; //questions.c
int id; //questions.c
int boolean; //questions.c
char id_fk[25]=""; //questions.c
char id_element[5]=""; //questions.c
MYSQL mysql; //co_deco_sql.c
MYSQL_ROW row; //co_deco_sql.c


/* INCLUDE DES FICHIERS */
#include "co_deco_sql.c"
#include "my_libsql.c"
#include "ldc.c"
#include "questions.c"
#include "gtk.c"
//Ajouter les fichiers de modif

int main (int argc, char **argv){
  int status;
  play(status, argc, argv);
  return status;
}
