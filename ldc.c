#include <string.h>
#include <mysql.h>
#include <stdlib.h>
#include <stdio.h>

#include "my_libsql.c"
#include "co_deco_sql.c"


int main(int argc,char** argv){
//var
int id_table;
char* name_table;

connect_bdd();

printf("Bienvenue dans le menu de modification \n");
printf("Ici, vous pouvez ajouter/modifier/supprimer une information \n");

printf("Voici les TABLES que vous pouvez modifier\n");
printf_tables();

printf("Quelle table voulez-vous modifer ? (entrez son numero)\n");
scanf("%d",&id_table);


close_mysql();
return 0;
}
