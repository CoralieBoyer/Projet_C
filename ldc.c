#include <string.h>
#include <mysql.h>
#include <stdlib.h>
#include <stdio.h>

#include "my_libsql.c"
#include "co_deco_sql.c"


int main(int argc,char** argv){
//var
char name_table[10];
char next;
int error;

connect_bdd();

printf("Bienvenue dans le menu de modification \n");
printf("Ici, vous pouvez ajouter/modifier/supprimer une information \n");

printf("Voici les TABLES que vous pouvez modifier\n");
printf_tables();

choose_table(name_table);//renvoie le nom de la table select
scanf("%c",&next);
if(next == 'n'){
	do{
		printf("Voulez-vous quitter (q) ou choisir une nouvelle table (c): ");
		clean_stdin();
		scanf("%c",&next);
		if(next == 'q')
                        return 0;
		if(next == 'c')
			break;
		}while(next != 'q' || next != 'c');

        if(next == 'c'){
            clean_stdin();
            choose_table(name_table);}//a countinuer
}
else if(next == 'o'){
	printf("Voulez-vous ajouter (a),modifier (m) ou supprimer (s) un element ?: ");
	clean_stdin();
	scanf("%c",&next);

	switch (next){
		case 'a':
			printf("a \n");
			break;
		case 'm':
			printf("m \n");
			break;
		case 's':
                        delete_element(name_table);
                        break;
		default://c pas encore quoi faire
                        printf("erreur \n");
                        break;
	}
}
close_mysql();
return 0;
}
