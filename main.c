//main ==>pour partie en ligne de commande

#include <stdio.h>
#include <mysql.h>
#include "test_my_lib.c" //func sql
//#include "co_deco_sql.c"
#include <string.h>

//prototype
void chose_table(int tables,char *table);

//func
void chose_table(int tables,char *table){
  switch(tables){
   case 1:
        strcpy(table,"AGE");
        break;
   case 2:
        strcpy(table,"EMPLOYE");
        break;
   case 3:
        strcpy(table,"ENTREPRISE");
        break;
   case 4:
        strcpy(table,"FICHIER");
        break;
   case 5:
        strcpy(table,"PHYSIQUE");
        break;
   case 6:
        strcpy(table,"QUESTIONS");
        break;
   case 7:
        strcpy(table,"TRAVAIL");
        break;
   case 8:
        strcpy(table,"VISAGE");
        break;
   default:
        printf("valeur inconnu, veuillez recommencer\n");
        break;
 };
}

//main
int modifyWindow() {
int tables;
char table[50]="false";
char menu;
char next='a';
int id;
int error;

  printf("Bienvenue dans le menu de modification\n");
  printf("Ici, vous pouvez ajouter/modifier/supprimer une information\n");

   //connect bdd
   //connect_bdd();

  printf("voici les TABLES modifiables :\n ");
  print_tables();//afficher tt les tables de la bdd

  printf("Quelle table voulez-vous modifer ? (entrez son numero)\n ");
  fflush(stdin);
  scanf("%d",&tables);

  //switch pour select table
  chose_table(tables,table);

  if(strstr(table,"false")==NULL){
  printf("Vous avez choisi la table %s. Continuez ? (o/n): ",table);
  fflush(stdin);
}else{
  printf("Recommencer ou quitter (r/q): ");
  }
  fflush(stdin);
  scanf("\n%c",&next);
  fflush(stdin);

  if(next == 'o'){
 	print_table(table);
 	printf("\nVoulez-vous ajouter (a),modifier (m) ou supprimer (s) un element ?: ");
 	scanf("\n%c",&menu);
	fflush(stdin);
	if(menu == 's'){
		printf("\nEntrez l'ID de l'element a supprimer: ");
		scanf("%d",&id);
		error = delete_element(table,id);
		if(error !=0){
			printf("erreur lors de la suppression\n");
		}else{
			printf("suppression reussie\n");
		}
	}else if(menu == 'a'){
	fflush(stdin);
	insert_table(tables);
	}
 }else if(next == 'n'){
	printf("Recommencer ou quitter (r/q): ");
	scanf("%c",&next);
 }
/*
   //insert
   insert_entreprise();

   //print * ENTREPRISE
   print_entreprise();
*/

  //close_mysql();
    return 0;
}

