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
char* var_table; //questions.c
int i; //questions.c
int id; //questions.c
int boolean; //questions.c
MYSQL mysql; //co_deco_sql.c
MYSQL_ROW row; //co_deco_sql.c


/* INCLUDE DES FICHIERS */
#include "co_deco_sql.c"
#include "questions.c"
#include "gtk.c"
//Ajouter les fichiers de modif

int main (int argc, char **argv){
  int status;
  play(status, argc, argv);
  return status;
}
